#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;

int main(){
	cin >> n;
	for(int i=0;i<20;i++) if((1<<i) == n) { puts("No"); return 0;}
	if(n%2 == 1){
		puts("Yes");
		if(n%4 == 3){
			for(int i=1;i<=2*n-1;i++) cout << i << " " << i+1 << endl;
		}
		else{
			vector<int>vi;
			for(int i=1;i<=n-2;i++) vi.pb(i);
			for(int i=1;i<=n-2;i++) vi.pb(i+n);
			cout << n-1 << " " << n << endl;
			cout << n << " " << 1 << endl;
			cout << 1 << " " << 2*n-1 << endl;
			cout << 2*n-1 << " " << 2*n << endl;
			for(int i=1;i<vi.size();i++) cout << vi[i-1] << " " << vi[i] << endl;
		}
	}
	else if(n%4 == 2){
		puts("Yes");
		{
			vector<int>vi;
			for(int i=1;i<=n-3;i++) vi.pb(i);
			for(int i=1;i<=n-3;i++) vi.pb(i+n);
			cout << n-2 << " " << n-1 << endl;
			cout << n-1 << " " << 1 << endl;
			cout << 1 << " " << 2*n-2 << endl;
			cout << 2*n-2 << " " << 2*n-1 << endl;
			for(int i=1;i<vi.size();i++) cout << vi[i-1] << " " << vi[i] << endl;
		}
		cout << n << " " << n-1 << endl;
		cout << 2 << " " << 2*n << endl;
	}
	else{
	    puts("Yes");
		vector<int>vec;
		vec.pb(n-1); vec.pb(n^(n-1));
		for(int i=1;i<=n-2;i++) if(i != (n^(n-1))) vec.pb(i);
		for(int i=0;i<n-2;i++) cout << vec[i] << " " << vec[i+1] << endl;
		cout << vec[n-2] << " " << vec[0]+n << endl;
		for(int i=0;i<n-2;i++) cout << vec[i]+n << " " << vec[i+1]+n << endl;
		cout << n << " " << vec[0] << endl;
		cout << vec[1] << " " << 2*n << endl;
	}
}
