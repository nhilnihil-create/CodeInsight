#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


int main(){
    int N, M; cin >> N >> M;
    vector<pair<int,int>> AB;
    vector<vector<int>> jobs(M); 
    rep(i,N){
        int a, b; cin >> a >> b;
        if (M < a) continue;
        jobs[M-a].push_back(b);
    }
    // 実行可能なジョブを格納するキュー
    priority_queue<int> que;
    ll ans = 0;
    for (int i = M-1; i >= 0; i--){
        // i日目で実行可能なジョブを追加
        for (int job : jobs[i]) que.push(job);        
        
        if (!que.empty()){
            ans += que.top(); que.pop();
        }
    }

    cout << ans << endl;
}