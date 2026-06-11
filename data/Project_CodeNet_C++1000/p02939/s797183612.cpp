#include <iostream>

int main(void){
    std::string S, a="", b="";
    int ans=0;
    std::cin >> S;

    for (char s: S){
        a += s;
        if (a != b){
            ++ans;
            b = a;
            a = "";
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
