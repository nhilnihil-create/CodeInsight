#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#define rep(i,n) for(int i=0; i<(n); ++i)
int main(){
    int n; std::cin >> n;
    std::vector<int> v(n), p(n), q(n);
    rep(i,n) std::cin >> p[i];
    rep(i,n) std::cin >> q[i];
    std::iota(v.begin(),v.end(),1);
    int a=-1, b=-1, cnt=1;
    do{
        if(v == p) a=cnt;
        if(v == q) b=cnt;
        ++cnt;
    }while(std::next_permutation(v.begin(),v.end()));
    std::cout << std::abs(b-a) << std::endl;
    return 0;
}