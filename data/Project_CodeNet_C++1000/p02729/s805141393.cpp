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

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	int tn = (n*(n-1))/2;
	int tm = (m*(m-1))/2;
	cout<<tn+tm<<endl;
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

//13*6 = 78