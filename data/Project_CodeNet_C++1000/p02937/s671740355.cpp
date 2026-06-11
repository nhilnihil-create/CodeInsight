#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int N_MAX = 1e5;
static const int C_MAX = 30;
int nx[C_MAX][N_MAX];
vector<vector<int>> idx(C_MAX);

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    for(int i = 0; i < n; i++){
        idx[s[i]-'a'].push_back(i);
    }
    for(int i = 0; i < C_MAX; i++){
        for(int j = 0; j < n; j++){
            if(idx[i].empty()) continue;
            nx[i][j] = idx[i][0] + n;
            for(auto k : idx[i]){
                if(j < k){
                    nx[i][j] = k;
                    break;
                }
            }
        }
    }
    if(idx[t[0]-'a'].empty()){
        cout << -1 << endl;
        return 0;
    }
    ll ans = idx[t[0]-'a'][0];
    for(int i = 1; i < t.size(); i++){
        if(idx[t[i]-'a'].empty()){
            cout << -1 << endl;
            return 0;
        }
        ans += nx[t[i]-'a'][ans % n] - (ans % n);
    }
    cout << ans + 1 << endl;
    return 0;
}