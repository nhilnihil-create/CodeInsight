#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void solve(){
	int n,m;
	cin >> n >> m;
	int count = 0;

	if(n&1)
	for(int i =0;i<m;i++){
		cout << i+1 << " " << (n-i) << endl;
	}
	else{
		for(int i=1,j=n/2;i<j;i++,j--){
			if(count>=m)
				break;
			cout << i << " " << j << endl;
			count++;
		}
		for(int i =n/2+1,j=n-1;i<j;i++,--j){
			if(count>=m)
				break;
			cout << i << " " << j << endl;
			
			count++;
		}
		// cout << count << endl;
	}
}

int main(){
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	// int t;cin >> t;while(t--)
		solve();
}
