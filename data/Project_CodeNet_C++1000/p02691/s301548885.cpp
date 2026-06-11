#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    map<ll, ll> m;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(m.count(i-a.at(i))){
            ans += m[i-a.at(i)];
        }
        m[i+a.at(i)]++;
    }
    cout << ans << endl;
}