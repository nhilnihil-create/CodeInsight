#include<iostream>

int main(void){
    int n;
    std::string s;
    std::cin >> n >> s;

    char start = 'A';
    char anum = 25;
    for(int i = 0; i < s.size(); i++){
	int num = s[i] - start;
	// std::cout << num << std::endl;
	char next;
	if(anum - num < n){
	    next = start;
	    next += n - anum + num - 1;
	    std::cout << next;
	}else{
	    next = s[i];
	    next += n;
	    std::cout << next;
	}
    }
    std::cout << std::endl;
    return 0;
}

