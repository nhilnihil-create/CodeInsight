#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //ansを出力する時は (ans % mod + mod) % mod とする(負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

vector<int> G[100005];
bool v[100005];



int main()
{
    int n,k;
    cin >> n >> k;
    ll d[100005];
    rep(i,100005) d[i] = -1;
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> q;
    v[0] = true;
    q.push(0);
    d[0] = 0;
    ll ans = k;
    while(!q.empty()){
        int now = q.front(); q.pop();
        ll cnt = k;
        if(d[now] == 0) cnt -= 1;
        else cnt -= 2;
        for(auto next : G[now]){
            if(d[next] == -1){
                q.push(next);
                d[next] = d[now] + 1;
                ans *= cnt;
                ans %= mod;
                cnt--;
            }
        }
    }
    cout << ans << endl;
}
