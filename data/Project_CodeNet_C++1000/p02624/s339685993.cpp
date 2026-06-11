#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> divisor(ll n){
    vector<ll> vec;
    for(ll i=1;i*i<= n;i++){
        if(n%i==0){
            vec.push_back(i);
            if(i*i!=n) vec.push_back(n/i);
        }
    }
    //sort(vec.begin(), vec.end());
    return vec;
}

int main(void){
    int n;
    cin >> n;

    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll y = n/i;
        ans += y*(y+1)*i/2;
    }
    cout << ans << endl;
    return 0;
}