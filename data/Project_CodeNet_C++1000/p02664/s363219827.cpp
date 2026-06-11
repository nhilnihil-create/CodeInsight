#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    string s;
    cin >> s;

    string ans = "";
    rep(i, s.size()){
        if(s[i] == '?')ans.push_back('D');
        else ans.push_back(s[i]);
    }

    cout << ans << endl;
}