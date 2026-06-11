#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf p
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	int cur = 1;
	for(int i=1;i<=20;i++){
		if( cur == n ){
			cout<<"No"<<endl;
			return 0;
		}
		cur *= 2;
	}
	vector< pair<int,int> > ed;
	ed.pb( mp(1,2) );
	ed.pb( mp(2,3) );
	ed.pb( mp(3,n+1) );
	ed.pb( mp(n+1,n+2) );
	ed.pb( mp(n+2,n+3) );
	for(int i=4;i<=n-1;i+=2){
		ed.pb(mp(i,1));
		ed.pb(mp(i+1,i));
		ed.pb(mp(1,i+1+n));
		ed.pb(mp(i+1+n,i+n));
	}
	if( n % 2 == 0 ){
		for(int i=4;i<=n-1;i++){
			if( (n^1^i) >= 4 && (n^1^i) != i && (n^1^i)<=n-1 ){
				int a = i;
				int b = n^i^1;
				if( a%2 ) a+=n;
				if( b%2 ) b+=n;
				ed.pb(mp(a,n));
				ed.pb(mp(b,n+n));
				goto endd;
			}
		}
		for(int i=4;i<=n-1;i++){
			if( (i^3) == n ){
				int a = i;
				if( a%2 ) a+=n;
				ed.pb( mp( a, n ) );
				ed.pb( mp( 2, n+n ) );
				goto endd;
			}
		}
		endd: n = n + 0;
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<ed.size();i++){
		cout<<ed[i].first<<" "<<ed[i].second<<endl;
	}		
	return 0;
}