#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
#define int ll
#define pb push_back
#define lb lower_bound

void pre() {
}

void solve() {
//    int n;
//    cin >> n;
//    vi a(n);
//    for (auto &i:a)cin >> i;
    string s;
    cin>>s;
    if(s.length()%2){
        cout<<"No";
        return;
    }
    for (int i = 0; i < s.length()-1; i+=2) {
        if(s[i]!='h' || s[i+1]!='i'){
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}

signed main() {
    pre();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}