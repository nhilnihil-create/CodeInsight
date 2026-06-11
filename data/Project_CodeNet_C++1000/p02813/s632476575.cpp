#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int n;
    cin >> n;
    vi p(n), q(n);
    rep(i,n) cin >> p.at(i);
    rep(i,n) cin >> q.at(i);

    vi r(n);
    rep(i,n) r.at(i) = i + 1;
    int P, Q;
    int cnt = 0;
    do {
        cnt++;
        rep(i,n){
            if (p.at(i) != r.at(i)) break;
            if (i == n-1) P = cnt;
        }
        rep(i,n){
            if (q.at(i) != r.at(i)) break;
            if (i == n-1) Q = cnt;
        }
    } while(next_permutation(r.begin(),r.end()));
    int ans = abs(P-Q);
    cout << ans << endl;
    return 0;
}
