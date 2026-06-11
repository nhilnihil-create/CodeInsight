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
   	
 //    int t;
 //     cin >> t;

 //     while(t--){


 // }
int n;
cin >> n;
vi v(n);
fo(i,0,n)cin >> v[i];

vi ith(n);
fo(i,0,n)ith[i] = i+1+v[i];
vi jth(n);
fo(i,0,n)jth[i] = i+1-v[i];
sort(all(jth));
sort(all(ith));
// fo(i,0,n)cout << ith[i] << ' ';
// cout << endl;
// fo(j,0,n)cout << jth[j] << ' ';
// cout << endl;
int count = 0;
fo(i,0,n){
	auto it1 = upper_bound(all(jth),ith[i]);
	auto it2 = lower_bound(all(jth),ith[i]);
	count += it1-it2;
}
cout << count << endl;



return 0;
	
	}


