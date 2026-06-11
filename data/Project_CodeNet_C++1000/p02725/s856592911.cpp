#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int n, k;
    cin >> n >> k;
    vi a(k), b(k);
    rep(i,k) cin >> a.at(i);
    rep(i,k-1) b.at(i) = a.at(i+1) - a.at(i);
    b.at(k-1) = a.at(0) + (n - a.at(k-1));
    sort(b.begin(), b.end());
    int ans = 0;
    rep(i,k-1) ans += b.at(i);
    // rep(i,k){
    //     printf("a:%d b:%d\n", a.at(i), b.at(i));
    // }
    cout << ans << endl;
    return 0;
}
