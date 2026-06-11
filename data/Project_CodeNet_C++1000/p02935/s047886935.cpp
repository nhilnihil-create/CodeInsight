#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    float ans = a[0];
    rep(i,n-1) ans = (ans+a[i+1])/2;
    cout << ans << endl;
}