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

     int n,k;
     cin >> n >> k;
     int arr[n];
     fo(i,0,n)cin >> arr[i];
     fo(i,0,n)arr[i]--;

     int j = 0;
     int i = 0;
     while(j < min(k,n)){
     	i = arr[i];
     	j++;
     }
     if(j == k)cout << i+1 << endl;
     else{
     	k = max(k-n,0ll);
     	set<int>s;
     	int count = 0;
     	while(1){
     		if(s.count(i))break;
     		s.insert(i);
     		i = arr[i];
     		count++;
     	}
     	k = k%count;
     	while(k> 0){
     		i = arr[i];
     		k--;
     	}
     	cout << i+1 << endl;

     } 



return 0;
	
	}


