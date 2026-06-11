#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//約数列挙
vector<ll> comdiv(ll x){
    vector<ll> res;
    stack<ll> big;
    for(ll i = 2; i*i <= x; i++){
        if(x%i == 0){
            res.push_back(i);
            if(x/i != i)big.push(x/i);
        } 
    }
    while(!big.empty()){
        res.push_back(big.top());
        big.pop();
    }
    res.push_back(x);
    return res;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a = comdiv(n);
    vector<ll> b = comdiv(n-1);
    ll ans = b.size();
    if(n == 2) ans--;
    //cout << ans <<endl;
    for(int i = 0; i < a.size(); i++){
        ll tmp = n;
        //cout << a[i] << endl;
        while(tmp%a[i] == 0){
            tmp /= a[i];
        }
        if(tmp%a[i] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
