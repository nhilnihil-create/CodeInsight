#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    ll T1,T2,A1,A2,B1,B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll p = (A1 - B1) * T1;
    ll q = (A2 - B2) * T2;
    if(p > 0){
        p *= -1;
        q *= -1;
    }
    if(p + q < 0){
        cout << 0 << endl;
    }else if(p + q == 0){
        cout << "infinity" << endl;
    }else{
        ll s = (-p) / (p + q);
        ll t = (-p) % (p + q);
        cout << (s * 2 + (t == 0 ? 0 : 1)) << endl;
    }
}