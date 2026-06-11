#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


int main(){
    int N;
    cin >> N;

    map<vector<char>,int> S;

    rep(i,N) {
        string s;
        cin >> s;
        vector<char> tmp;
        rep(j,s.size()) {
            tmp.push_back(s[j]);
        }
        sort(tmp.begin(),tmp.end());
        S[tmp]++;
    }
    ll ans = 0;

    for (auto p:S) {
        ll n = p.second;

        if (n>=2) {
            ans += n*(n-1)/2;
        }
    }
    cout << ans << endl;
}