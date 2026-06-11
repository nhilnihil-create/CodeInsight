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
     int n;
     cin >> n;
     vector<int> a(n+1,0);
     for(int i = 1; i <= n; i++){
     	for(int j = 0; j <= n; j += i)
     		a[j]++;
     }
     ll total = 0;
     for(ll i = 1; i <= n; i++)
     	total += i*a[i];
     cout << total;
     return 0;
}