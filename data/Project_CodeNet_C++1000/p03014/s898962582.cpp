#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))

int main(){
    FAST
    int n, m; cin >> n >> m;
    vector<int> rows[n + 2];
    vector<int> cols[m + 2];
    int lastOR[n + 2];
    int lastOC[m + 2];
    mm(lastOR); mm(lastOC);
    string mat[n + 2];
    string s = " ";
    for(int i = 0; i < m + 2; i++){
        s += '#';
    }
    mat[0] = s;
    mat[n + 1] = s;
    for(int i = 1; i <= n; i++){
        cin >> mat[i];
        mat[i] = '#' + mat[i];
        mat[i] += '#';
    }
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            if(mat[i][j] == '#'){
                rows[i].pb(j);
                cols[j].pb(i);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            if(mat[i][j] == '.'){
                int curr = j - lastOR[i] + i - lastOC[j] - 1;
                int ind = lower_bound(rows[i].begin(), rows[i].end(), j) - rows[i].begin();
                if(rows[i].size() == ind){
                    curr += m - j - 1;
                }
                else{
                    ind = rows[i][ind];
                    curr += ind - j - 1;
                }
                ind = lower_bound(cols[j].begin(), cols[j].end(), i) - cols[j].begin();
                if(ind == cols[j].size()){
                    curr += n - i - 1;
                }
                else{
                    ind = cols[j][ind];
                    curr += ind - i - 1;
                }
                ans = max(ans, curr);
            }
            else{
                lastOR[i] = j;
                lastOC[j] = i;
            }
        }
    }
    cout << ans;
    return 0;
}
