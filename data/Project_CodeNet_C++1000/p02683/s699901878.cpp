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

     int n,m,k;
     cin >> n >> m >> k;
     vi c(n);
     vvi v(n,vi(m));
     fo(i,0,n){
     	cin >> c[i];
     	fo(j,0,m)cin >> v[i][j];
     }




     int x  =  (1 << n);
     int mi = 1e9;
     fo(i,1,x){
     	vi var(m);
     	int x = i;
     	vi pos;
     	int count = 0;
     	while(x > 0){
     		if(x&1)pos.pb(count);
     		x = x  >> 1;
     		count++;
     	}
     	int sum = 0;
     	// for(auto a : pos)cout << a << ' ';
     	// 	cout << endl;
     	for(auto a : pos){
     		sum += c[a];
     		fo(j,0,m)var[j] += v[a][j]; 
     	}
     	int flag = 0;
     	// if(sum == 120){
     	// 	fo(j,0,n){
     	// 		fo(p,0,m)cout << v[j][p] <<  ' ';
     	// 		cout << endl;
     	// 	}
     	// }
     	fo(j,0,m){
     		if(var[j] < k){
     			flag = 1;
     			break;
     		}
     	}
     	// cout << sum << endl;

     	if(flag == 0)
     		mi = min(sum,mi);


     }
     if(mi == (int)1e9)cout << -1  << endl;
     else cout << mi << endl;




return 0;
	
	}


