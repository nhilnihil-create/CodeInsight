#include<iostream>

int main(void){
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}