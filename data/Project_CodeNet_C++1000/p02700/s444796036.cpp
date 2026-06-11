#include <iostream>

#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int a,b,c,d; std::cin >> a >> b >> c >> d;
    while(1){
        c -= b;
        if(c <= 0) break;
        a -= d;
        if(a <= 0) break;
    }
    std::string ans="Yes";
    if(a<=0)
        ans="No";
    std::cout << ans << std::endl;

    return 0;
}