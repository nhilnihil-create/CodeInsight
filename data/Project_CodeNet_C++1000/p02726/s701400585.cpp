#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

void code() {
    int n,x,y;
    cin>>n>>x>>y;
    int ans=0;
    vector<int> distx(n+1);
    vector<int> disty(n+1);
    vector<vector<int> > adj(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            adj[i][j] = min(abs(i-j), min(abs(i-x)+1+abs(j-y), abs(j-x)+1+abs(i-y)));
        }
    }
    vector<int> dist(n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dist[adj[i][j]]++;
        }
    }

    for(int i=1; i<n; i++)
        cout << dist[i]/2 << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    for(int i=0; i<t; i++) {
        code();
    }
}
