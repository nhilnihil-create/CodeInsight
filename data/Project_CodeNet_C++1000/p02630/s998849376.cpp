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







int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
   	
//     int t;
//      cin >> t;

//      while(t--){
    
// }
int n;
cin >> n;
int arr[n];
fo(i,0,n)cin >> arr[i];

int q;
cin >> q;
int sum = 0;
fo(i,0,n)sum += arr[i];
map<int,int>m;
fo(i,0,n)m[arr[i]]++;
while(q--){
	int b,c;
	cin >> b >> c;
	int x = m[b];
	m[c] += x;
	m[b] = 0;
	int re = c*x - b*x;
	sum += re;
	cout << sum << endl;
}


return 0;
}


