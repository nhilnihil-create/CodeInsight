#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;
typedef pair<ll,ll> Pl;
typedef vector<ll> vl;
typedef vector<Pl> vpl;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b <= 0) return -1;
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}


int main() {
    int N;
    cin >> N;
    vector<vpi> ab(N);
    //vector<vector<bool>> ch(N, vector<bool>(N ,false));
    vi ans(N-1, 0), Vp(N, 0);

    rep(i,N-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        ab[a].push_back(make_pair(b, i));
        ab[b].push_back(make_pair(a, i));
    }

    //次数が一番大きい頂点の探索
    int m_d = 0, m_dindex;
    rep(i,N) {
        if((int)ab[i].size() > m_d) {
            m_d = (int)ab[i].size();
            m_dindex = i;
        }
    }

    //根から幅優先探索
    queue<int> que;
    que.push(m_dindex);
    while(!que.empty()) {
        int nr = que.front(); que.pop();

        //色塗り
        int clnum = 0;
        rep(i, ab[nr].size()) {
            if(ans[ab[nr][i].second] != 0) continue;

            //塗られていない辺に塗る色の決定
            clnum++;
            if(clnum == Vp[nr]) clnum++;
            ans[ab[nr][i].second] = clnum;
            que.push(ab[nr][i].first);
            Vp[ab[nr][i].first] = clnum; //親とつながる辺の色を記録
        }
    }

    cout << m_d << "\n";
    rep(i, N-1) cout << ans[i] << "\n";
    //string ans = ( flag ? "Yes" : "No" );
    //printf("%.8lf", ans);
    //cout << ans;
    //cout << "\n";
    return 0;
}
