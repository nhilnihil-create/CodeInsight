#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int long long

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

typedef pair<int, int> pint;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front

#define MOD (1000 * 1000 * 1000 + 7)

void set_map(vector<vector <int> > &m, int i, int j, int v) {
    m[i][j] = v;
    m[j][i] = v;
}

void solve(vector<vector <int> > &m, int N, vector<int> nodes, vector<int> used) {
    if (N <= 1) return;

    // cout << "solve = " << N << endl;
    // REP(i, N) {
    //     cout << nodes[i] << ", ";
    // }
    // cout << endl;

    vector< vector<int>> group(2, vector<int>());
    REP(i, N) {
        group[i%2].pb(nodes[i]);
    }

    int next = 0;
    while (used[next] == 1) next++;
    used[next] = 1;

    for (int i: group[0]) {
        for (int j: group[1]) {
            set_map(m, i, j, next);
        }
    }

    solve(m, SZ(group[0]), group[0], used);
    solve(m, SZ(group[1]), group[1], used);
}

signed main() {
    int N;
    cin >> N;

    vector<vector <int> > m(N, vector<int>(N, 0));

    vector<int> used(N*N, 0);
    used[0] = 1;

    vector<int> nodes;
    REP(i, N) {
        nodes.pb(i);
    }

    solve(m, N, nodes, used);

    int max_v = 0;
    REP(i, N-1) {
        // REP(j, i) cout << "  ";
        FOR(j, i+1, N) {
            if  (j > i+1) cout << " ";
            cout << m[i][j];
            max_v = max(max_v, m[i][j]);
        }
        cout << endl;
    }

    // cout << max_v << endl;


    return 0;
}