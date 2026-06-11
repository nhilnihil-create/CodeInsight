#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    int hanten = 0;
    vector<vector<char>> vsc(2);
    REP(i, q)
    {
        int a;
        cin >> a;
        if (a == 1)
            hanten = (hanten + 1) % 2;
        if (a == 2) {
            int b;
            char c;
            cin >> b >> c;
            vsc[(b - 1 + hanten) % 2].push_back(c);
        }
    }
    if (hanten == 0) {
        REP(i,vsc[0].size()){
            cout<<vsc[0][vsc[0].size()-1-i];
        }
        cout<<s;
        REP(i,vsc[1].size()){
            cout<<vsc[1][i];
        }
    } else {
        REP(i,vsc[1].size()){
            cout<<vsc[1][vsc[1].size()-1-i];
        }
        REP(i,s.length())
        cout<<s[s.length()-1-i];
        REP(i,vsc[0].size()){
            cout<<vsc[0][i];
        }
    }
    cout<<endl;
}