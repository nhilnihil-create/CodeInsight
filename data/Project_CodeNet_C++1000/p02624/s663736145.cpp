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

const int m = 1e7+5;
vi v(m);
void sieve(int n){
	fo(i,0,n+1)v[i] = 1;
	for(int i = 2; i <= n; i+= 2)v[i]++;
	for(int i =3; i <= n;i++){
		for(int j = i; j <= n;j += i){
			v[j]++;
			// cout << v[j] << ' ';
		}
		// cout << endl;
	}
}

int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
   	
    // int t;
     // cin >> t;

//      while(t--){

// }
     int n;
     cin >> n;
     sieve(n);
     int res = 0;
     for(int i = 1;i <= n; i++){
     	res += i*v[i];
     	// cout << v[i] << endl;
     }

cout << res << endl;


return 0;
}



