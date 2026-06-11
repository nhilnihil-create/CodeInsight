#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll INF = (1LL<<60);
const int INFi = (1<<29);

int main(){

    ll n, d; cin >> n >> d;
    vvll x(n, vll(d));
    rep(i, n){
        rep(j, d){
            cin >> x[i][j];
        }
    }

    ll ans = 0;
    rep(i, n-1){
        rep2(j, i+1, n){
            ld sum = 0.0;
            rep(k, d){
                sum += pow(x[i][k]-x[j][k], 2); 
            }
            ld dist = sqrt(sum);
            if(floor(dist)==ceil(dist)){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}