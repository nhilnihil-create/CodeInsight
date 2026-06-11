#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define pii pair<int, int> 
#define all(a) a.begin(), a.end()
#define int long long
#define ll long long
#define vi vector<int>
#define vip vector<pii>
#define mod1 998244353
#define mod 1000000007
#define endl "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
#define bloop(i,a,b) for(int i=a;i>=b;i--)
#define testcase  int t; cin>>t; while(t--) 
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);

using namespace std;

int max(int a, int b) { return (a > b)? a : b; } 

int min(int a, int b) { return (a < b)? a : b; }


   
/*************************************************************************/



int32_t main() {
	
	FIO
	// testcase
	{
		int a,v,b,w,ti;
		cin>>a>>v>>b>>w>>ti;
		int sa,sb;
		// sa = v*ti+a;
		// sb = w*ti+b;
		if(w>=v)
			cout<<"NO"<<endl;
		else if(ti*(v-w)>=abs(b-a))
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}