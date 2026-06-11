#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int n;
vector<vector<int>> G(100005);
vector<int> col(100005, -1);

void solve(int deep){
    set<int> st;

    for (auto& p : G[deep]) {
        if(col[p] != -1){
            st.insert(col[p]);
        }
    }

    int cnt = 1;
    for (auto& p : G[deep]) {
        if(col[p] == -1){
            while(st.count(cnt)) cnt++;
            st.insert(cnt);
            col[p] = cnt++;
            //cnt++;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(i);
        G[b].push_back(i);
    }

    int ans = 0;
    rep(i, n){
        ans = max(ans, (int)G[i].size());
    }
    cout << ans << "\n";

    rep(i, n){
        solve(i);
    }


    rep(i, n-1){
        cout << col[i] << "\n";
    }


    return 0;
}
