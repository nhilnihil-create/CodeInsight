#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
# define ll  long long int
# define ld  long double
# define pb push_back
# define pp pop_back
# define ff first
# define ss second
# define mp make_pair
# define ac accumulate
# define mod 1000000007
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int  main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
     IOS
     int n,m;
     ll k;
     cin >> n >> m >> k;
     vector<ll> a,b;
     for(int i = 0; i < n; i++){
     	ll x;
     	cin >> x;
     	a.pb(x);
     }
     for(int i = 0; i < m; i++){
     	ll x;
     	cin >> x;
     	b.pb(x);
     }
     vector<ll> a1(n + 1), b1(m + 1);
     a1[0] = 0;
     b1[0] = 0;
     for(int i  = 1, j = 0; i <= n; i++, j++){
     	a1[i] = a1[i - 1] + a[j];
     }
     for(int i  = 1, j = 0; i <= m; i++, j++){
     	b1[i] = b1[i - 1] + b[j];
     }
     //ll cnt1 = (upper_bound(b1.begin(), b1.end(), k) - b1.begin());
     ll cnt1 = 0;
     for(int i = 0; i <= n; i++){
     	ll rem = k - a1[i];
     	if(rem < 0)
     		break;
     	ll ans = i + (upper_bound(b1.begin(), b1.end(), rem) - b1.begin()) - 1;
     	cnt1 = max(cnt1, ans);
     }
     //ll cnt2 = (upper_bound(a1.begin(), a1.end(), k) - a1.begin());
     ll cnt2 = 0;
     for(int i = 0; i <= m; i++){
     	ll rem = k - b1[i];
     	if(rem < 0)
     		break;
     	ll ans = i + (upper_bound(a1.begin(), a1.end(), rem) - a1.begin()) - 1;
     	cnt2 = max(cnt2, ans);
     }
     cout << max(cnt1, cnt2);
     return 0;
}