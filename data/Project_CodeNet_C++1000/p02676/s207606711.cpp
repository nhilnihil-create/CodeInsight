#include<iostream>
#include<vector>

int main(void){
    int k;
    std::string s;
    std::cin >> k >> s;
    int ss = s.size();
    if(ss <= k) std::cout << s << std::endl;
    else{
	for(int i = 0; i < k; i++){
	    std::cout << s[i];
	}
	std::cout << "..." << std::endl;
    }
    return 0;
}
