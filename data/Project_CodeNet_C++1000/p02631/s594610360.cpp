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

void solve(){
	int n;
	cin >> n;
	int arr[n];
	int xo = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		xo = xo^arr[i];
	}
	for(int i = 0; i < n; i++)
		cout << (xo^arr[i]) << " ";
}

int  main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
     IOS;
     int t = 1;
     //cin >> t;
     while(t--){
     	solve();
     }
     return 0;
    
}