#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	ll n,m;
	cin>>n>>m;
	vi a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	ll lcm = a[0];
	for(int i=1;i<n;++i){
		lcm = lcm/__gcd((ll)a[i],lcm)*(ll)a[i];
	}
	for(int i=0;i<n;++i){
		if(((lcm/2)-a[i]/2)%a[i]!=0){
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<(m-(lcm/2)+lcm)/lcm<<endl;
	return 0;
}