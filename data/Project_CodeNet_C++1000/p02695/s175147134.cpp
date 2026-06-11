#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
typedef long long ll;
constexpr auto INFI = 2147483647;
const ll INFL = 9223372036854775807;

int main()
{
    int n, m, q, a, b, c, d;
    int ans = 0;
    vector<vector<int>> query_list;
    cin >> n >> m >> q;
    rep(i, q)
    {
        cin >> a >> b >> c >> d;
        a--; b--;
        vector<int> q = {a, b, c, d};
        query_list.push_back(q);
    }
    vector<vector<int>> comb_list;
    vector<int> start = {1};
    comb_list.push_back(start);
    rep(i,n-1){
        vector<vector<int>> new_comb_list;
        for (auto comb_pre : comb_list) {
            for (int k = comb_pre[comb_pre.size()-1]; k <= m; k++){
                vector<int> comb_tmp = comb_pre;
                comb_tmp.push_back(k);
                new_comb_list.push_back(comb_tmp);
            }
        }
        comb_list = new_comb_list;
    }

    for (auto comb : comb_list){
        int score = 0;
        for (auto q : query_list){
            if (comb[q[1]] -comb[q[0]] == q[2]) score += q[3];
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
    return 0;
}
