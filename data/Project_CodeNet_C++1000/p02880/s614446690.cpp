#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forr(i,n) for(int i = 0;i < (int)n; i++)
#define forn(i,n) for(int i = (int)(n-1); ~i ;i--)
#define deb(x) cout<<#x<<" " <<x<<"\n";
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define pb push_back
#define mpa make_pair
#define endl "\n"
#define ar array

vector<int> done(101);

void solve(){
	int n;
	cin >> n;
	if(done[n]) cout << "Yes";
	else cout << "No";
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	forr(i,9){
		forr(j,9){
			done[(i+1)*(j+1)] = 1;
		}
	}
	int t = 1;
	//cin>>t;
	while(t--){
		solve();		
	}
	return 0;
}
