#include<iostream>

int main(void){
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 1;
    char b = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] != b){
            cnt++;
            b = s[i];
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}