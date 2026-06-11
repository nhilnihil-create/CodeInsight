#include<iostream>

int main(void){
    std::string s, t;
    std::cin >> s >> t;
    int ss = s.size();

    if(ss + 1 != t.size()){
	std::cout << "No" << std::endl;
	return 0;
    }

    for(int i = 0; i < ss; i++){
	if(s[i] != t[i]){
	    std::cout << "No" << std::endl;
	    return 0;
	}
    }


    std::cout << "Yes" << std::endl;

    return 0;
}
