#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}
const int NM = 1e5+1;
vector<int> ab[NM];
vector<P> ipt;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    rep(i, n-1){
        int a,b;cin>>a>>b;
        ipt.push_back(make_pair(a,b));
        ab[a].push_back(b);
        ab[b].push_back(a);
    }
    map<P, int> color; // 辺の色
    int ngcol[NM] = {0}; //頂点に紐づく色
    // 幅優先探索
    queue<int> q;
    q.push(1); // 頂点1からはじめる
    int mx = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        int col = 1;
        for(int next : ab[now]){
            int x=now, y=next; 
            if(x>y) swap(x,y);
            P pa = make_pair(x, y);
            if(color[pa] == 0){
                // 彩色
                if(col == ngcol[now]) col++;
                color[pa] = col; 
                ngcol[next]=col; mx = max(mx, col);
                q.push(next);
                col++;
            }
        }
    }
    cout<<mx<<endl;
    for(P p : ipt){
        cout<<color[p]<<endl;
    }

}