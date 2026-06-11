#include <bits/stdc++.h>
using namespace std;


void solve(std::vector<long long> x){
    long long ans = 0;
    for(int i = 0; i < x.size(); ++i){
        if(x[i] != i+1) ans = i+1;
    }
    cout << ans << endl;
    return;
}

int main(){
    std::vector<long long> x(5);
    for(int i = 0 ; i < 5 ; i++){
        scanf("%lld",&x[i]);
    }
    solve(std::move(x));
    return 0;
}
