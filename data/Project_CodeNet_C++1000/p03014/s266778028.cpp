#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<string> s;
int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];

int main()
{
    int h, w; cin >> h >> w;
    s.resize(h);
    rep(i, h) cin >> s[i];

    rep(i, h)
    {
        int cur = 0;
        rep(j, w)
        {
            if (s[i][j] == '#') cur = 0;
            else cur++;
            Left[i][j] = cur;
        }
    }

    rep(i, h)
    {
        int cur = 0;
        RRep(j, w - 1, -1)
        {
            if (s[i][j] == '#') cur = 0;
            else cur++;
            Right[i][j] = cur;
        }
    }

    rep(j, w)
    {
        int cur = 0;
        rep(i, h)
        {
            if (s[i][j] == '#') cur = 0;
            else cur++;
            Up[i][j] = cur;
        }
    }

    rep(j, w)
    {
        int cur = 0;
        RRep(i, h - 1, -1)
        {
            if (s[i][j] == '#') cur = 0;
            else cur++;
            Down[i][j] = cur;
        }
    }

    int res = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '#') continue;
            res = max(res, Left[i][j] + Right[i][j] + Up[i][j] + Down[i][j] - 3);
        }
    }
    cout << res << endl;
}