#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
 
typedef long long ll;
typedef pair<int, int> ii;
 
int main(){

	int n;
	cin >> n;
	ll ans = 1;
	REP(i, 2, n+1){
		ans *= (ll)i;
	}
	
	cout << ans << endl;
	
	return 0;
}