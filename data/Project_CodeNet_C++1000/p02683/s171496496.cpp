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

ll pow(ll a,ll p,ll m=mod)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%m;p>>=1;}
return res;}

vvi allsubsets;

void generate(vi c,int n,vi res){
	if(c.size() == 0){
		if(res.size() > 0)
		allsubsets.pb(res);
		return;
	}

	vi cx;
	fo(i,1,c.size())cx.pb(c[i]);
	vi resx;
	fo(i,0,res.size())resx.pb(res[i]);
	if(c.size() > 0)
	resx.pb(c[0]);

	generate(cx,n,res);
	generate(cx,n,resx);

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

int n,m,x;
cin >> n >> m >> x;
vi c(n);
int mat[n][m];
fo(i,0,n){
	cin >> c[i];
	fo(j,0,m){
		cin >> mat[i][j];
	}
}
vi res;
vi ind;
fo(i,0,n)ind.pb(i);
generate(ind,n,res);
int mi = 1e9;
for(auto a : allsubsets){
	int sum = 0;
	vi sec(m);
	for(auto b : a){
		sum += c[b];

	}
	for(auto b: a){
		// cout << b << ' ';
		for(int j = 0;j < m;j++)sec[j] += mat[b][j];
	}

	int flag = 1;
	
		fo(j,0,m){
			if(sec[j] < x){
				flag = 0;
				break;
			}
		}
	
	if(flag){
		mi = min(mi,sum);
	}
}
if(mi == (int)1e9)cout << -1 << endl;
else cout << mi << endl;
return 0;
	
	}


