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


int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
   	
//      int t;
//      cin >> t;
//      while(t--){


// }

int n,m,k;
cin >> n >> m >> k;
vi a(n+1);
vi b(m+1);
fo(i,1,n+1)cin >> a[i];
fo(i,1,m+1)cin >> b[i];
fo(i,1,n+1){
	a[i] += a[i-1];
}
fo(j,1,m+1){
	b[j] += b[j-1];
}
int ans = 0;
int j = m;
fo(i,0,n+1){
	if(a[i] > k)break;
	while(b[j] > k-a[i])j--;
	ans = max(ans,i+j);
}
cout << ans << endl;
return 0;
}

