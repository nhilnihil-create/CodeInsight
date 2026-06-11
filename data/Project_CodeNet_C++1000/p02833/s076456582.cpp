#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll N;
    cin >> N;
    if(N % 2 == 1){ 
        cout << 0 << endl;
        return 0;
    }else{
        ll ans = 0;
        for(ll i = 10; i <= N; i*=5){
            ans += N/i;
        }
        cout << ans << endl;
        return 0;
    }
}