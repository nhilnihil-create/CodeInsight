#include <bits/stdc++.h>

#define REP( i, n )     for( int (i) = 0; (i) < (n); (i)++ )
#define ALL( a )        (a).begin(), (a).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int V, E;
vector<int> G[10001];
vector<int> ans;
int indeg[10001];
bool seen[10001];

void dfs( int s ){
    seen[s] = true;

    for( auto nv : G[s] ){
        if( seen[nv] ) continue;
        dfs( nv );
    }

    ans.emplace_back( s );
}

int main(){
    cin >> V >> E;
    REP( i, E ){
        int s, t; cin >> s >> t;
        G[s].emplace_back( t );
        indeg[t]++;
    }

    REP( i, V ){
        if( indeg[i] == 0 ){
            dfs( i );
        }
    }

    REP( i, ans.size() ) cout << ans[ans.size() - i - 1] << endl;

}

/*

*/
