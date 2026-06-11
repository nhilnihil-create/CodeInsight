// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;




int main(){	
	int n,m;cin>>n>>m;
	vector<int>uwu;
	ll tot=0;
	For(i,0,n){
		int val;cin>>val;
		tot+=val;
		while(val>0){
			int cur=(val>>1)+(val&1);
			uwu.pb(cur);
			val>>=1;
		}
	}
	sort(uwu.rbegin(),uwu.rend());
	ll here=0;
	For(i,0,min(m,sz(uwu))){
		here+=uwu[i];
	}
	cout<<tot-here<<endl;

	return 0;
}
