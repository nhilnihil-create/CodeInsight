#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

ll rec[2000][2000];
vector<VVP> DAG;

ll dfs(PL p){
    ll ret = 0;
    if(rec[p.first][p.second] != -1) return rec[p.first][p.second];
    for(auto g : DAG[p.first][p.second]){
        ret = max(dfs(g), ret);
    }
    rec[p.first][p.second] = ret + 1;
    return ret + 1;
}

int main(){
    ll N;
    cin >> N;
    VVL A(N+1, VL(N-1));
    rep(i, 1, N+1){
        rep(j, 0, N-1) cin >> A[i][j];
    }

    DAG.resize(N+1, VVP(N+1));
    VVL h(N+1, VL(N+1, 0));
    rep(i, 1, N+1){
        rep(j, 0, N-2){
            DAG[min(i, A[i][j])][max(i, A[i][j])].push_back({min(i, A[i][j+1]),max(i, A[i][j+1])});
            h[min(i, A[i][j+1])][max(i, A[i][j+1])]++;
        }
    }
    
    queue<PL> que;
    stack<PL> st;
    rep(i, 1, N){
        rep(j, i+1, N+1){
            if(h[i][j] == 0){
                st.push({i,j});
                que.push({i,j});
            }
        }
    }
    
    vector<PL> tps;
    while(!st.empty()){
        auto s = st.top();
        st.pop();
        tps.push_back(s);
        for(auto j : DAG[s.first][s.second]){
            h[j.first][j.second]--;
            if(h[j.first][j.second] == 0){
                st.push(j);
            }
        }
    }

    ll v = N*(N-1)/2;
    cerr << v << "," << tps.size() << endl;
    if(tps.size() != v){
        cout << -1 << endl;
        return 0;
    }

    rep(i, 0, 2000){
        rep(j, 0, 2000) rec[i][j] = -1;
    }

    ll ans = 0;
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        ans = max(ans, dfs(q));
    }
    
    cout << ans << endl;
    return 0;
}