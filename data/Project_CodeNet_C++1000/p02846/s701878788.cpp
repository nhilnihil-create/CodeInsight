#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    ll t1, t2; cin >> t1 >> t2;
    ll a1, a2; cin >> a1 >> a2;
    ll b1, b2; cin >> b1 >> b2;
    ll p = a1*t1 - b1*t1;
    ll q = a2*t2 - b2*t2;
    if(p < 0){
        p *= -1;
        q *= -1;
    }
    if((p + q) > 0){
        cout << 0 << endl;
        return 0;
    }
    if((p + q) == 0){
        cout << "infinity" << endl;
        return 0;
    }
    ll s = p / (-1*(p+q));
    ll t = p % (-1*(p+q));
    if(t == 0) cout << 2*s << endl;
    else cout << 2*s + 1 << endl;
}