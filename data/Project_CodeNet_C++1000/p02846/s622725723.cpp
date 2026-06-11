#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define Endl endl
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2>>a1>>a2>>b1>>b2;
	int s1 = t1 * ( a1 - b1 );
	int s2 = t2 * ( a2 - b2 );
	if( ( s1 > 0 && s2 > 0 ) || (s1 < 0 && s2 <0) || ( abs(s1) > abs(s2) ) ){
		cout<<0<<endl;
		return 0;
	}
	else{
		if( s1 + s2 == 0 ){
			cout<<"infinity"<<endl;
			return 0;
		}
		else{
			int sa = abs( abs(s1) - abs(s2) );
			int mi = min( abs(s1), abs(s2) );
			int sp = mi/sa + 1;
			if( mi % sa == 0 ) sp--;
			int ans = sp*2-1;
			if( mi % sa == 0 ) ans++;
			cout<<ans<<endl;
			return 0;
		}
	}
	return 0;
}