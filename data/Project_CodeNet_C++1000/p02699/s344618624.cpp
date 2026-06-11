#include <iostream>

#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int s,w; std::cin >> s >> w;
    std::string ans;
    if(s<=w)
        ans="unsafe";
    else
        ans="safe";
    std::cout << ans << std::endl;
    return 0;
}