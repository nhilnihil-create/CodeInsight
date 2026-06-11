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
	int n,k;
	cin >> n >> k;
	vi a(n);
	forn(i,0,n) cin >> a[i];

	while(k--){
		vi b(n+1);
		for(int i =0;i<n;i++){
			int from = max(i-a[i],0);
			int to = min(n-1,i+a[i]);
			b[from]+=1;
			if(to<n-1)
				b[to+1]-=1;
 		}

 		vi cpya = a;

 		for(int i =0;i<n;i++){
 			a[i]=b[i];
 			b[i+1]+=b[i];
 		}
 		if(cpya == a)
 			break;
 		// for(int i =0;i<n;i+)
	}

	for(int i =0;i<n;i++){
			cout << a[i] << " ";
	}cout << endl;
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}
