#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int N, M, Q;
ll ans = 0;
vector<vector<int>> query;

void dfs(vector<int> a){
    if(a.size() == N){
        ll tmp = 0;
        rep(i, Q){
            if(a[query[i][1] - 1] - a[query[i][0] - 1] == query[i][2]) tmp += query[i][3];
        }
        ans = max(ans, tmp);
        return;
    }
    for(int i = a.back(); i <= M; i++){
        a.push_back(i);
        dfs(a);
        a.pop_back();
    }
}

int main(){
    cin >> N >> M >> Q;
    query.assign(Q, vector<int>(4, 0));
    rep(i, Q) cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];

    rep(i, M){
        vector<int> mat;
        mat.push_back(i + 1);
        dfs(mat);
    }
    cout << ans << endl;
}