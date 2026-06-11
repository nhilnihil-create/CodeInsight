#include <iostream>
#include <set>

#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n; std::cin >> n;
    std::set<std::string> ss;
    rep(i,n){
        std::string s; std::cin >> s;
        ss.insert(s);
    }
    std::cout << ss.size() << std::endl;
    return 0;
}