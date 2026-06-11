#include<iostream>

int main(void){
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    char ss = s[0];
    int i = 0;
    while(k != 0 && i != n){
        if(s[i] == ss){
            i++;
        }else{
            while(s[i] != ss && i != n){
                s[i] = ss;
                i++;
            }
            k--;
        }
    }

    int ans = 0;
    ss = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] == ss) ans++;
        else ss = s[i];
    }
    std::cout << ans << std::endl;
    return 0;
}