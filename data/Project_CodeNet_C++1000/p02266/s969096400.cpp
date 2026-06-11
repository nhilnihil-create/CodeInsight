#include <iostream>
#include <vector>

int main(int argc, char const *argv[]){
	std::string law_data;
	std::cin >> law_data;
	int area = 0;
	int cnt = 0;
	std::vector< std::pair<int,int> > areas;
	std::vector<int> stack;

	for (int i = 0; i < law_data.length(); ++i){
		switch(law_data[i]){
			case '\\':
					stack.push_back(i);
					break;
			case '/':
					if(!stack.empty()){
						int j = stack.back();
						stack.pop_back();
						int buff = i - j;
						area += buff;
						while( !areas.empty() &&areas.back().first > j){
							buff += areas.back().second;
							areas.pop_back();
						}
						areas.push_back(std::make_pair(j,buff));
					}
					break;
			case '_':
					break;
			default:
					return 0;
					break;
		}
	}

	std::cout << area <<std::endl;
	std::cout << areas.size();
	for (int i = 0; i < areas.size(); ++i){
	 	std::cout << " " << areas[i].second;
	} 
	std::cout << std::endl;

	return 0;
}
