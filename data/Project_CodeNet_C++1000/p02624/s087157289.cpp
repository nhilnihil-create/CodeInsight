#include <bits/stdc++.h>

#define mp make_pair
#define ff first
#define ss second
#define pii pair <int,int>
#define pb push_back
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std ;
typedef long long ll ;
const int mx = 10000000+5 ;
int d[mx] ;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue <int> a,b ;
	int n;
	cin >> n ;
	for(int i=1 ;i<=n ; i++){
		for(int j=i ; j<=n ; j+=i){
			d[j]++;
		}
	}
//	for(int i=1 ;i<= n; i++){
//		cout << i << ' ' <<d[i] << '\n' ;
//	}
	ll ans=0 ;
	for(int i =1 ; i<=n ; i++){
		ans = (ll)ans + (ll)i*(ll)d[i] ;
	}
	cout  << ans ;
	
	return 0 ;
}
