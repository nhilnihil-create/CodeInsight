#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

ll T1, T2, A1, A2, B1, B2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll d1 = (T1 * A1 + T2 * A2) - (T1 * B1 + T2 * B2); 
    if(d1 == 0){
        cout << "infinity" << endl;
        return 0;
    }
    ll d2 = T1 * A1 - T1 * B1;
    ll ans = 1 + 2 * abs(d2 / d1);
    if(abs(d2) % abs(d1) == 0) ans--;
    cout << (d2 > 0 ^ d1 > 0 ? ans : 0) << endl;
    return 0;
}