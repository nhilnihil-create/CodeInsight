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


int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
   	
 //    int t;
 //     cin >> t;

 //     while(t--){


 // }

     int n,m;
     cin >> n >> m;
     vi height(n);
     vi adj[n];
     fo(i,0,n)cin >> height[i];
     fo(i,0,m){
     	int a,b;
     	cin >> a >> b;
     	a--;
     	b--;
     	adj[a].pb(b);
     	adj[b].pb(a);
     }
     vi greater(n);
     for(int i = 0;i < n;i++){
     	if(adj[i].size() == 0)greater[i] = 1;
     	else{
     		int ma = height[i];
     		int flag = 0;
     		for(int j = 0;j < adj[i].size();j++){
     			if(ma <= height[adj[i][j]]){
     				flag = 1;
     				break;
     			}
     		}
     		if(flag)continue;
     		greater[i] = 1;
     	}
     }
     int count = 0;
     fo(i,0,n)
     	if(greater[i])count++;

     cout << count << endl;
     

return 0;
	
	}


