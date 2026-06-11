#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, n, k) for (int i = n; i < k; i++)
#define P(p) cout << (p) << endl;
#define sP(p) cout << setprecision(24) << fixed << p << endl;
#define vi vector<int>
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        P(v[i]);
#define printt(a, b) cout << a << " " << b << endl;
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b; //先に割り算をして掛けられる数を小さくして掛け算を行う
}

bool pairCompare(const pair<int, int> &firstElof, const pair<int, int> &secondElof)
{
    return firstElof.second < secondElof.second;
}

void solve()
{
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> vs;
    rep(i,h){
        string s;
        cin >> s;
        vs.push_back(s);
    }
    int count = 0;
    for(int i = 0; i < (1<<h);i++){
        for(int j = 0;j < (1<<w);j++){
            int bcount = 0;
            rep(k,h)rep(l,w){
                if(i & (1<<k) && j & (1<<l) && vs[k][l] == '#') bcount++;
            }
            if(bcount == k)count++;
        }
    }
    P(count);
}

int main()
{
    solve();
    return 0;
}
