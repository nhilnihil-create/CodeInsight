#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(std::vector<long long> x){
    ll ans = 0;
    rep(i,x.size()){
        if(x[i] == 0) ans = i+1;
    }
    cout << ans << endl;
}

int main(){
    std::vector<long long> x(5);
    for(int i = 0 ; i < 5 ; i++){
        scanf("%lld",&x[i]);
    }
    solve(std::move(x));
    return 0;
}
