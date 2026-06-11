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
     IOS;
     int n;
     cin >> n;
     string s;
     cin >> s;
     int i = 0, j = 0;
     int cnt = 0;
     while(i < n && j < n){
     	if(s[i] == s[j] && s[i] == 'R'){
     		j++;
     		i++;
     	}
     	else if(s[i] == s[j] && s[i] == 'W')
     		i++;
     	else{
     		if(s[i] == 'R'){
     			cnt++;
     			i++;
     			j++;
     		}
     		else{
     			i++;
     		}
     	}
     }
     cout << cnt;
     return 0;
}