#include<iostream>
#include<vector>
#include<algorithm>
int main(void){
    std::vector<std::string> a = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    std::reverse(a.begin(), a.end());
    std::string s;
    std::cin >> s;
    for(int i = 0; i < a.size(); i++){
	if(a[i] == s){
	    std::cout << ++i << std::endl;
	    break;
	}
    }
    return 0;
}

