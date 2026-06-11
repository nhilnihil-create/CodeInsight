
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    rep(i,n) cin >> a[i];

    double ans=0;
    rep(i,n){
        ans += 1/a[i];
    }
    ans = 1/ans;

    cout << setprecision(10) << ans << endl;
}