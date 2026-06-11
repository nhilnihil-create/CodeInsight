#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    map<ll, ll> ball;
    vector<int> z(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin >> a;
        ball[a]++;
        z.at(i) = a;
    }
    ll all=0;
    for(auto p: ball){
        auto v=p.second;
        all += v*(v-1)/2;
    }
    for(int i=0; i<n; i++){
        //sはボールに書かれている数、tはその数が全体で何個あるか
        ll s=z.at(i);
        ll t=ball[s];
        ll ans = all-t*(t-1)/2+(t-1)*(t-2)/2;
        cout << ans << endl; 
    }
}
