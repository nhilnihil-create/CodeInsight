#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(N,vector<ll>(2));

    rep(i,N) {
        ll x,y;
        cin >> x >> y;
        A[i][0] = x;
        A[i][1] = y;
    }

    set<P> S;
    rep(i,N) {
        rep(j,N) {
            if (i==j) continue;
            int p = A[j][0]-A[i][0];
            int q = A[j][1]-A[i][1];
            P tmp = make_pair(p,q);
            S.insert(tmp);
            tmp = make_pair(-p,-q);
            S.insert(tmp);
        }
    }
    int ans = 0;
    for (auto s:S){
        int p = s.first;
        int q = s.second;
        int tmp = 0;
        rep(i,N) {
            rep(j,N) {
                if (i==j) continue;
                if (A[i][0]-A[j][0]==p && A[i][1]-A[j][1]==q) {
                    tmp++;
                }

            }
        }
        ans = max(ans,tmp);
    }
    ans = N-ans;
    cout << ans << endl;

}