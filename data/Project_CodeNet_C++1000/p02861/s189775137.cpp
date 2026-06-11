#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

double ans = 0;

void dis(double x1,double y1,double x2,double y2){
     ans += sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void solve(){
    double n;cin >> n;
    vector<double>a(n);
    vector<double>b(n);
    vector<int>p(n);
    for(int i = 0;i<n;i++) p[i] = i;
    for(int i = 0;i<n;i++) cin >> a[i] >> b[i];
    do{
        for(int i = 0;i<n-1;i++)
            dis(a[p[i]],b[p[i]],a[p[i+1]],b[p[i+1]]);
    }
    while(next_permutation(p.begin(),p.end()));
    double fac = 1;
    for(int i = 1;i<=n;i++) fac *= i;
    cout << fixed << setprecision(10) <<(ans/fac);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}