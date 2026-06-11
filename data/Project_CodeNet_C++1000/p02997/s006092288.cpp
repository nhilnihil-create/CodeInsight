#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n, k;
    cin >> n >> k;

    
    if (k>(n-1)*(n-2)/2) {
        cout << "-1" << endl;
        return 0;
    }
    
    
    int m = n-1 + ((n-1)*(n-2)/2-k);
    cout << m << endl;
    for (int i=2; i<=n; i++) {
        cout << "1 " << i << endl;
        m--;
    }
    if (m==0) return 0;
    for (int i=2; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            cout << i << " " << j << endl;
            m--;
            if (m==0) return 0;
        }
    }
    
    
    return 0;
}
