#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

bool is_prime[1000010];

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    x--,y--;
    vector<vector<int>> dist(n,vector<int>(n,-1));
    for (int s = 0; s < n; ++s) {
        queue<int> q;
        q.push(s);
        dist[s][s] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            vector<int> next;
            if(v > 0) next.push_back(v-1);
            if(v < n-1) next.push_back(v+1);
            if(v == x) next.push_back(y);
            if(v == y) next.push_back(x);

            for(auto nv:next){
                if(dist[s][nv] == -1){
                    dist[s][nv] = dist[s][v]+1;
                    q.push(nv);
                }
            }
        }
    }
    vector<int> ans(n,0);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ans[dist[i][j]]++;
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}