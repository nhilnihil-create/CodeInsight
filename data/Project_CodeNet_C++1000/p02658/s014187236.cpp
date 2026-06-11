#include <bits/stdc++.h>
using namespace std;
//型名省略
typedef long long ll;
typedef vector<long long> vl;
typedef vector<vector<long long>> vll;
typedef vector<char> vc;
typedef vector<vector<char>> vcc;
typedef vector<string> vs;
//マクロ
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define rep2(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define all(A) A.begin(), A.end()

int main() {
    unsigned long long n,ans=1; cin >> n;
    vector<unsigned long long> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    sort(all(a));
    rep(i,n){
        if(a[i] <= 1000000000000000000/ans){
            ans *= a[i];
            if(ans == 0){
                cout << 0 << endl;
                return 0;
            }
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

}