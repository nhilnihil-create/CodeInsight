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
// auto start = high_resolution_clock::now(); 
// auto stop = high_resolution_clock::now(); 
// auto duration = duration_cast<microseconds>(stop - start); 
 
// cout << duration.count() << endl; 


int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
//      int t;
//      cin >> t; 
//      while(t--){
     	
// }

    int n;
    cin >> n;
    string s;
    cin >> s;

int r = 0;
int b = 0,g = 0;

fo(i,0,n){
	if(s[i] == 'R')r++;
	else if(s[i] == 'B')b++;
	else g++;
}

int res = r*b*g;
int neg = 0;
fo(i,0,n){
	fo(j,i+1,n){
		int k = j + j- i;
			if(k < n){
				if(s[i] != s[j] && s[i] != s[k] && s[j] != s[k])neg++;
			}
			}

			}
cout << res-neg << endl;


return 0;
}
