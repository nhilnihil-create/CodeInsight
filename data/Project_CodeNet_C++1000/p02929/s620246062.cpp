#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1;
    ll cnt = 0;
    for(int i = 1; i <= n; ++i) {
        ans*=i;
        ans%=mod;
    }
    for(int i = 0; i < 2 * n; ++i) {
        if((cnt&1)==(s[i]=='B')) {
            ans*=cnt;
            ans%=mod;
            --cnt;
        }else{
            ++cnt;
        }
    }
    if(cnt) {
        cout<<0<< endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}

