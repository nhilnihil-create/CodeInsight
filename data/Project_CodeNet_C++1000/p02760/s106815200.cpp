#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) ((a+b-1)/(b))
using namespace std;

const int MAX = 100010;
const int MOD = 1000000007;
const int INF = (int)1e9;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-7;

// Extra
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define dbg(msg, var) cout << msg << " " << var << endl;
#define ti tuple<int,int,int>
//

int main() {
    int s = 3;

    vector<vi> mat(3, vi(3, 0));
    forn(i, s) {
        forn(j, s) {
            cin >> mat[i][j];
        }
    }

    int n;
    cin >> n;

    forn(i, n) {
        int val;
        cin >> val;

        forn(i, s) {
            forn(j, s) {
                if(mat[i][j] == val)
                    mat[i][j] = -1;
            }
        }
    }

    bool win = false;
    forn(i, s) {
        int qt = 0;
        forn(j, s) {
            if(mat[i][j] == -1)
                qt++;
        }
        if(qt == s) {
            win = true;
        }
    }

    forn(j, s) {
        int qt = 0;
        forn(i, s) {
            if(mat[i][j] == -1)
                qt++;
        }
        if(qt == s) {
            win = true;
        }
    }

    {
        int qt = 0;
        forn(i, s) {
            if(mat[i][i] == -1)
                qt++;
        }
        if(qt == s)
            win = true;
    }

    {
        int qt = 0;
        forn(i, s) {
            if(mat[i][s-i-1] == -1)
                qt++;
        }
        if(qt == s)
            win = true;
    }

    if(win)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
