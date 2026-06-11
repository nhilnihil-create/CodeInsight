#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    while (cin >> n >> k) {
        vector<ll>a(n),b(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }
        sort(all(a));
        sort(all(b));
        reverse(all(b));
        ll l = -1, r = 1e12;
        while (r - l > 1) {
            ll mid = (l + r) >> 1;
            ll sum = 0;
            for (int i = 0 ; i < n ; i++) {
                ll mx = mid / b[i];
                sum += max(0LL,a[i] - mx);
            }
            if (sum <= k) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << r << endl;
    }
}
