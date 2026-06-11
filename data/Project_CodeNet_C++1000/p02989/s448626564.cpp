#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(all(d));
    int ans = d[n/2]-d[n/2-1];
    cout << ans << endl;

}