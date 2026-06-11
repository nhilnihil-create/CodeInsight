#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int maxn = 1e5+10;
const int mod = 1e9+7;
const double eps = 1e-8;

using namespace std;

void solve(){
	int a,b,ans=-1;
	cin>>a>>b;
	for(int i=1;i<=1000;++i){
		double x1 = floor(i*0.08);
		double x2 = floor(i*0.1);
		if(x1==a&&x2==b){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}