#include <bits/stdc++.h>
// #include <chrono>
// #include <math.h>
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
#define float long double
#define all(c) (c).begin(), (c).end()
#define endl '\n'
#define pi 3.14159265358979323846
 
ll power(ll a,ll p,ll m=mod)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%m;p>>=1;}
return res;}
 
int pow(int a,int b){
	if(b == 0)return 1;
	int res = pow(a,b/2);
	res = res*res;
	if(b&1)res *= a;
	return res;
}



int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);

// int t;
// cin >> t;
// while(t--){



// }

int n,m;
cin >> n >> m;

int arr[n];
ld total = 0;
fo(i,0,n)cin >> arr[i];
// fo(i,0,n)cout << arr[i] << ' ';
// cout << endl;

fo(i,0,n)total += arr[i];
total = total/4;
total = total/m;


total = ceil(total);
int count = 0;
for(int i = 0; i< n;i++){
	if(arr[i] < total)continue;
	count++;
}

if(count >= m)cout << "Yes" << endl;
else cout << "No" << endl;


return 0;
	
	}
