#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define sz(x)                 x.size()
#define all(x)                x.begin(), x.end()
#define tr(x, it)             for(auto it = x.begin();it != x.end();it++)
#define fo(i, k, n)           for(int i = k;i < n;i++)
#define Fo(i, k, n)           for(int i = k;i >= n;i--)
#define el                    "\n"
#define ff                    first
#define ss                    second
#define ll                    long long
#define pb                    push_back
#define mp                    make_pair
#define pii                   pair<int, int>
#define vi                    vector<int>
#define mii                   map<int, int>
//#define pqb                   priority_queue<int>
//#define pqs                   priority_queue<int, vi, greater<int>>
//#define pc(x)                 putchar(x);
//#define setbits(x)            __builtin_popcountll(x)
//#define zrobits(x)            __builtin_ctzll(x)
#define mod                   1000000007
#define inf                   1e18
#define deb(x)                cout<<#x<< " = "<< x<<"\n";
//#define ps(x, y)              fixed<<setprecision(y)<<x
//#define mk(arr, n, type)      type *arr = new type[n];
//#define w(x)                  int x; cin>>x; while(x--)

void solve(){
	int l, r, d;
	cin>>l>>r>>d;
	int ans = 0;
	fo(i, l, r+1){
		if(i%d == 0){
			ans++;
		}
	}
	cout<<ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
//	cin>>t;
	while(t--){
		solve();
		cout<<el;
	}
	return 0;
}
