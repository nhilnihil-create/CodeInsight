#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
using ll = long long;
using ld = long double;
using namespace std::chrono; 
#define fo(i,z,n) for(int i = z;i<n;i++)
#define Fo(i,z,n) for(ll i = z;i<n;i++)
#define INT_BITS 32
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> > 
#define pb push_back
#define f first
// #define s second
#define int long long
#define all(c) (c).begin(), (c).end()
#define endl '\n'

ll pow(ll a,ll p,ll m=mod)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%m;p>>=1;}
return res;}




int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
   	
//      int t;
//      cin >> t;
//      while(t--){



// }

int x,n;
cin >> x >> n;
int arr[n];
fo(i,0,n)cin >> arr[i];

int mi = mod;
int mians = 0;
fo(i,-500,500){
	int j;
	for(j=0;j < n;j++){
		if(i == arr[j])break;
	}
	if(j == n){
		if(mi > abs(x-i)){
			mians = i;
			mi = abs(x-i);
		}
	}
}
cout << mians << endl;




return 0;
}

