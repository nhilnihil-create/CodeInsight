#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

int main()
{
    int H,W;
    cin >> H >> W;
    vector<string> s(H);
    rep(i, H) cin >> s[i];

    const int INF = 100100100;

    vector<vector<int>> c(H, vector<int>(W, INF));

    queue<tuple<int,int>> q;
    q.push(make_tuple(0,0));
    c[0][0] = 0;

    int dh[] = {0, 1};
    int dw[] = {1, 0};

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        int h = get<0>(p);
        int w = get<1>(p);

        int cost = c[h][w];

        for(int i=0;i<2;i++){
            int nh = h + dh[i];
            int nw = w+dw[i];

            if(nh < H && nw < W) {
                int a = (s[h][w] == s[nh][nw] ? 0 : 1);
                if(chmin(c[nh][nw], c[h][w]+a)){
                    q.push(make_tuple(nh, nw));
                }
            }
        }
    }

    int ans = c[H - 1][W - 1];

    if (s[0][0] == '#' && s[H - 1][W - 1] == '#'){
        ans = ans / 2 + 1;

    } else if(s[0][0] == '.' && s[H - 1][W - 1] == '.'){
        ans = ans / 2;
    }else{
        ans = (ans + 1) / 2;
    }


    cout << ans << endl;
}
