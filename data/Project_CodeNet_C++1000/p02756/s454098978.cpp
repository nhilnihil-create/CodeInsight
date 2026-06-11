#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
    string s;
    cin >> s;
    ll n = s.size(), q, cur = 0, x, in;
    cin >> q;
    char ch;
    while(q--){
        cin >> in;
        if(in == 1){
            cur ^= 1;
        }
        else {
            cin >> x >> ch;
            if(x == 1){
                if(cur){
                    s.pb(ch);
                }
                else s.insert(s.begin(),ch);
            }
            else {
                if(cur){
                    s.insert(s.begin(),ch);
                }
                else s.pb(ch);
            }
        }
    }
    if(cur)reverse(all(s));
    cout << s << nl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
