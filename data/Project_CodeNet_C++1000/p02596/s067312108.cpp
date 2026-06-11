#include <bits/stdc++.h>

using namespace std;
 
//#define int long long
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define reps(i,n) for(ll i=0;i<=n;i++)

ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
 
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ios_base::sync_with_stdio(false);
    ll k;
    cin >> k;
    vector<ll> a(k,0);
    a[1]=7;
    for(int i=1;i<=k;i++){
        if(i!=1){
            a[i]=(10*a[i-1]+7);
            a[i]%=k;
        }
        if(a[i]%k==0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
