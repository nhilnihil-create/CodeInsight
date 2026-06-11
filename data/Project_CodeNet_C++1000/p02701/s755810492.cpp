#include <iostream>
#include <set>
#include <string>


int main(void){
	std::string s = "";
	int N = 0;
	std::set<std::string> goods;

	std::cin >> N;
	for(int i = 0; i < N; i++){
		std::cin >> s;
		goods.insert(s);
	}

	std::cout << goods.size() << std::endl;
	return 0;
}
