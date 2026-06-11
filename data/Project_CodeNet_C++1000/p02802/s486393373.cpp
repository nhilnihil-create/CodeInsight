#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, M;
int WA[105000];
bool AC[1050000];

void solve() {
    cin >> N >> M;
    int WAnum = 0;
    int ACnum = 0;
    for (int i = 1; i <= N; i++)
    {
        WA[i] = 0;
        AC[i] = false;
    }
    while (M--)
    {
        int p;
        string S;
        cin >> p >> S;
        if (AC[p])continue;
        if (S=="AC")
        {
            AC[p] = true;
            ACnum++;
            WAnum += WA[p];
        }
        else if (S == "WA") {
            WA[p]++;
        }
    }
    cout << ACnum << " " << WAnum << endl;
    return;
}

int main()
{
    solve();
    return 0;
}