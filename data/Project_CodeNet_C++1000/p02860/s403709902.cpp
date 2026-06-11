#include<iostream>

int main(void){
    int n;
    std::string s;
    std::cin >> n >> s;
    if(s.size() % 2 == 1){
	std::cout << "No" << std::endl;
	return 0;
    }else{
	int mid = s.size() / 2;
	for(int i = 0; i < mid; i++){
	    if(s[i] != s[i + mid]){
		std::cout << "No" << std::endl;
		return 0;
	    }
	}
    }
    std::cout << "Yes" << std::endl;
    
    return 0;
}

