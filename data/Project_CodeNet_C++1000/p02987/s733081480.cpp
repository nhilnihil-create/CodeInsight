#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    sort(be(s));
    if(s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
