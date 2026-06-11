#include<bits/stdc++.h>
using namespace std;
using Int = long long;
int main(){
    Int N; cin >> N;
    Int ans = 0;
    for(Int i = 1; i <= N; ++i){
        Int div = N / i;
        ans += (div) * (div + 1) / 2 * i;
    }
    cout << ans << endl;
}


