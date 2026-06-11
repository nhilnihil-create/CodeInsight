#include<iostream>
int main(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int cnt=0;
    int idx=0;
    while(idx<s.size()){
        while(idx < s.size() && s[idx] != 'A') ++idx;
        if(idx >= s.size()) break;
        if(s.substr(idx,3) == "ABC") ++cnt;
        ++idx;
    }
    std::cout << cnt << std::endl;
    return 0;
}