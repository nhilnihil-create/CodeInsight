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
int a[n];
fo(i,0,n)cin >> a[i];
map<int,int> m;
fo(i,0,n){
	m[a[i]]++;
}
vi arr;
for(auto it = m.begin(); it != m.end();it++){
	if(it->second == 1)arr.pb(it->first);
}
n = arr.size();

// for(int i = 0;i < n;i++)cout << arr[i] << ' ';
// 	cout << endl;

if(n == 0){
	cout << 0 << endl;

}

else{
int mq = 1e6+1;
vi dp(mq,1);
for(auto it = m.begin(); it != m.end();it++){
	if(it->second > 1){arr.pb(it->first);
	dp[it->first] = 0;}	
}

sort(all(arr));
n = arr.size();
int ma = arr[n-1];

if(0){}
else{
// cout << endl;
fo(i,0,n){
	// if(dp[arr[i]]){
	for(int j = arr[i]*2; j <= ma;j += arr[i]){
		dp[j] = 0;
	}
// }
}
int count = 0;
fo(i,0,n){
	if(dp[arr[i]])count++;
}

cout << count << endl;

}
}
return 0;
}


