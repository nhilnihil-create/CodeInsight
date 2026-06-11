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

string mat[7];
int n, m, k;
vector< vector<bool > > vec;
vector< vector<bool > > vec2;
void color1(bool rows[], int ind1){
    if(ind1 == n){
        vector<bool> aa;
        for(int i = 0; i < n; i++){
            aa.pb(rows[i]);
        }
        vec.pb(aa);
        return;
    }
    color1(rows, ind1 + 1);
    rows[ind1] = 1;
    color1(rows, ind1 + 1);
    rows[ind1] = 0;
}
void color2(bool cols[], int ind1){
    if(ind1 == m){
        vector<bool> aa;
        for(int i = 0; i < m; i++){
            aa.pb(cols[i]);
        }
        vec2.pb(aa);
        return;
    }
    color2(cols, ind1 + 1);
    cols[ind1] = 1;
    color2(cols, ind1 + 1);
    cols[ind1] = 0;
}
int main(){
    FAST
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> mat[i];
    }
    bool done1[n + 1], done2[m + 1];
    mm(done1); mm(done2);
    color1(done1, 0); color2(done2, 0);
    int ans = 0;
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec2.size(); j++){
            int cnt = 0;
            for(int a = 0; a < n; a++){
                if(vec[i][a])continue;
                for(int b = 0; b < m; b++){
                    if(vec2[j][b])continue;
                    if(mat[a][b] == '#')cnt++;
                }
            }
            if(cnt == k)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
