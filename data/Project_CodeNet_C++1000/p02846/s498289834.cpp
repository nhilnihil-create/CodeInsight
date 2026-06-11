#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll C1 = A1-B1, C2 = A2-B2, D1 = C1*T1, D2 = C2*T2;
    if(D1+D2 == 0 || D1*D2 == 0) cout << "infinity" << endl;
    elif(D1+D2 > 0){
        if(D1 > 0) cout << 0 << endl;
        else{
            if((-D1)%(D1+D2) == 0){
                cout << 2*((-D1)/(D1+D2)) << endl;
            }
            else{
                cout << 2*((-D1)/(D1+D2))+1 << endl;
            }
        }
    }
    else{
        if(D1 < 0) cout << 0 << endl;
        else{
            if(D1%(-D1-D2) == 0){
                cout << 2*(D1/(-D1-D2)) << endl;
            }
            else{
                cout << 2*(D1/(-D1-D2))+1 << endl;
            }
        }
    }
}