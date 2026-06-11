#include<iostream>

int main(void){
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W') cnt++;
    }
    int ans = 0;
    for(int i = n - cnt; i < n; i++){
        if(s[i] == 'R') ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}