#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;
const int N = 1e5 + 10;
double a[N*2];
int n, k;
bool check(double x) {
    int ans=0;
    for (int i=1;i<=n;++i) {
        ans+=int(a[i]/x);
    }
    if (ans>k) return false;
    else return true;
}
void solve()
{
    cin>>n>>k;
    double m=0;
    for (int i=1;i<=n;++i) {
    	cin>>a[i]; 
    	a[i]=a[i]-0.001; 
    	m=max(m, a[i]);
    }
    double l=0, r=m;
    while ((r-l)>1e-6) {
        double mid=(l+r)/2;
        if (check(mid)) {
            r=mid;
        }
        else {
            l=mid;
        }
    }
    r=ceil(r);
    printf("%.0lf\n",r);

}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // freopen("data1.txt", "r", stdin);
    // freopen("data2.txt", "w", stdout);
    int _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; ++i)
        solve();
    // system("pause");
}