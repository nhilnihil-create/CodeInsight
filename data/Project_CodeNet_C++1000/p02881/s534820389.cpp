#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll ans = 1000000000000;
    ll num;
    bool judge;
    for(ll i = 1; i*i <= N; i++){
        if(N % i == 0){
            num = N / i + i - 2;
            ans = min(ans, num);
        }
    }
    cout << ans << endl;   
}