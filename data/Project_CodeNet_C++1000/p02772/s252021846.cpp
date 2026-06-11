#include<iostream>
#include<vector>

#define ll long long
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n; std::cin >> n;
    std::vector<int> a;
    rep(i,n){
        int b; std::cin >> b;
        if(b%2 == 0) a.push_back(b);
    }
    std::string s="APPROVED";
    for(auto v : a)
        if(v%3 != 0 && v%5 != 0) s="DENIED";
    std::cout << s << std::endl;
    return 0;
}