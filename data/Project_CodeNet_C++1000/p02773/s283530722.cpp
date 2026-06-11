#include<iostream>
#include<vector>
#include<map>
int main(void){
    int n;
    std::cin >> n;
    std::map<std::string, int> m;
    for(int i = 0; i < n; i++){
	std::string s;
	std::cin >> s;
	m[s]++;
    }
    int max = 0;
    for(auto i : m){
	max = std::max(max, i.second);
    }
    for(auto i : m){
	if(i.second == max){
	    std::cout << i.first << std::endl;
	}
    }
    return 0;
}

