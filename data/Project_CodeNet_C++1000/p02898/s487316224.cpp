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
	int n,k,ans=0;
	cin >> n >> k;
	for(int i=0,x;i<n;++i){
		cin >> x;
		ans+=(x>=k);
	}
	cout<<ans<<endl;
	return 0;
}