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

int x,y;
cin >> x >> y;
	
	int b= (y-2*x)/2;
	int a = (4*x-y)/2;
	if(y&1)cout << "No" << endl;
	else if(b < 0 || a < 0)cout << "No" << endl;
	else cout << "Yes" << endl;
return 0;
}

