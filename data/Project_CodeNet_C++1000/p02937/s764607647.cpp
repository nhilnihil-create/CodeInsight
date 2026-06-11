#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


vector<ll> alph[26];

int main(){
    string s, t;
    cin >> s >> t;

    rep(i, s.size()){
        int p = s[i] - 'a';
        alph[p].push_back(i);
    }
    ll num = 0;
    ll now = 0;

    rep(i, t.size()){
        ll c = t[i] - 'a';
        if (alph[c].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        ll len = alph[c].size();
        ll idx_last = distance(alph[c].begin(), lower_bound(alph[c].begin(), alph[c].end(), now));
        
        if (idx_last == len) {
            now = alph[c][0] + 1, num++;
        }
        else now = alph[c][idx_last] + 1;
        // cout << t[i] << ", idx=" << idx_last << ", len=" << len <<  endl;
        // cout << "now=" << now << " num=" << num << endl;
    }
    cout << num * ll(s.size()) + now << endl;
    return 0;
}