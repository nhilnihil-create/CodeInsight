#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int a, b; // a:N-S b:E-W
	std::cin >> a >> b;

	while(a != 0 || b != 0){
		int n; // n:work place
		std::cin >> n;
		std::vector<std::vector<int>> work;
		work.resize(b);

		int buf_x, buf_y;
		for(int i = 0; i < n; ++i){
			std::cin >> buf_x >> buf_y;
			work.at(buf_y - 1).push_back(buf_x - 1);
		}

		std::vector<int> way;
		way.resize(a);
		way[0] = 1;
		for(int i = 0; i < b; ++i){
			for(int j = 0; j < a; ++j){
				if(std::find(work[i].begin(), work[i].end(), j)	== work[i].end()){
					if(j != 0) way[j] += way[j-1];
				}else{
					way[j] = 0;
				}
			}
		}

		std::cout << way[a-1] << std::endl;

		std::cin >> a >> b;
	}


	return 0;
}