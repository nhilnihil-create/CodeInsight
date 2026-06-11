#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001;

vector<int> E[100005];
map<ll, int> mp;

void dfs(int f, int t, int num) {
    ll key = (ll)f*100000+t;
    ll key2 = (ll)t*100000+f;
    mp[key] = num;
    mp[key2] = num;
    int cnt = 1;
    for (auto e : E[t]) {
        if (e != f) {
            if (num != cnt) dfs(t,e,cnt);
            else {
                cnt++;
                dfs(t,e,cnt);
            }
            cnt++;
        }
    }
}

int main() {
    int n; cin >> n;
    int a,b;
    pair<int,int> edge[n-1];
    rep(i,n-1) {
        cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
        edge[i] = {a,b};
    }
    dfs(-1,0,0);
    int k = 0;
    for(auto itr = mp.begin(); itr != mp.end(); itr++) {
        k = max(k, itr->second);
    }
    cout << k << endl;
    rep(i,n-1) {
        ll key = (ll)edge[i].first*100000+edge[i].second;
        printf("%d\n",mp[key]);
    }
    return 0;
}
