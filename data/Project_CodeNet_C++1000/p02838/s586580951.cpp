#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main(void){
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];

    ll ans = 0;
    ll d = 1;

    //桁ごとにみて(0の個数*1の個数)*2^iを加算
    for(int i=0;i<60;i++){
        ll num0 = 0, num1 = 0;

        for(int j=0;j<n;j++){
            if(vec[j]%2==1) num1++;
            else num0++;

            vec[j] /= 2;
        }
        ll add = num0*num1;
        add %= mod;
        ans += d*add;
        ans %= mod;
        
        d *= 2;
        d %= mod;
    }    
    cout << ans << endl;
    return 0;
}