#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
#define mod 1000000007
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dx8[]={1,-1,0,0,1,1,-1,-1};
int dy8[]={0,0,1,-1,1,-1,1,-1};
ll binexp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll modinvfermat(ll a, ll m)
{
	return binexp(a, m - 2, m);
}
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
ll lcm(ll a, ll b)
{
	return ((1LL * a * b) / (__gcd(a, b)));
}



//ll a[]={6,8,4,2,6};

//ll tb=100;
void solve(){
	ll x,y;
	cin>>x>>y;
	ll maxl=x*4;
	ll minl=x*2;
	if(y>=minl&&y<=maxl&&y%2==0){
		cout<<"Yes"<<endl;

	}
	else{
		cout<<"No"<<endl;
	}



		
}



int main()
{  
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
    fast;
    ll t;
    t=1;
   // cin>>t;
    while(t--){
    	solve();
    }
    
   
  



#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
return 0;
}