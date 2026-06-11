#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a, f;
ll n, k;

bool chk(ll x){
    ll sum=0;
    vector<ll> t(n);
        for(int i=0; i<n; i++)
            t.at(i) = x/f.at(i);
        for(int i=0; i<n; i++)
            sum += max(0LL, a.at(i)-t.at(i));
    return sum <= k;
}



int main(){
    cin >> n >> k;
    a.resize(n); f.resize(n);

    for(int i=0; i<n; i++)  cin >> a.at(i);
    for(int i=0; i<n; i++)  cin >> f.at(i);
    sort(a.begin(), a.end(), greater<ll>());
    sort(f.begin(), f.end());

    ll l=-1, r=1e+15;
    while(l+1<r){
        ll mid = (l+r)/2;
        if(chk(mid)) r = mid;
        else l = mid;
    }
    
    
    cout << l+1 << endl; 
}
