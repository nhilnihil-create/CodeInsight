#include<iostream>
#include<set>

int main(void){
    int n;
    std::cin >> n;
    std::string st;
    std::set<std::string> s;

    for(int i = 0; i < n; i++){
	std::cin >> st;
	s.insert(st);
    }
    std::cout << s.size() << std::endl;
    return 0;
}

