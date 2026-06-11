#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()
 
const int INF = 1e9;
const ll LINF = 1e16;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
 
    while(1){
        int m, nmin, nmax;
        cin >> m >> nmin >> nmax;
        if (m == 0 && nmin == 0 && nmax == 0)break;
        vector<int> P(m);
        for (int i = 0; i < m; i++) cin >> P[i];
        int MAX = -1;
        int ret = 0;
        for (int i = nmin; i <= nmax; i++) {
            if (P[i - 1] - P[i] >= MAX) {
                MAX = P[i - 1] - P[i];
                ret = i;
            }
        }
        cout << ret << endl;
    }
     
  return 0;
}