#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<long long> calc_divisor(long long n) {//約数列挙
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    vector<int> div(1000100,0);
    rep(i,n){
        div[v[i]]++;
    }
    int ans = 0;
    rep(i,n){
        bool ok = 1;
        //cout << v[i] << "tern" << endl;
        for(auto u : calc_divisor(v[i])){
            if(div[u]>0 && u != v[i]){
                //cout << u << endl;
                ok = 0;
                break;
            }
        }
        if(div[v[i]] > 1) ok = 0;
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
