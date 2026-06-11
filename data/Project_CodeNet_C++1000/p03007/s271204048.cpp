#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	sort( a.begin(), a.end() );
	int ne = 0, po = 0;
	for(int i=0;i<n;i++){
		if( a[i] < 0 )ne++;
		else po++;
	}
	queue<int> negat, posit;
	if( ne == 0 ){
		negat.push( a[0] );
		for(int i=1;i<n;i++){
			posit.push(a[i]);
		}
	}
	else if( po == 0 ){
		for(int i=0;i<n-1;i++){
			negat.push(a[i]);
		}
		posit.push(a[n-1]);
	}
	else{
		for(int i=0;i<n;i++){
			if( a[i] < 0 )negat.push( a[i] );
			else posit.push(a[i]);
		}
	}
	vector< pair<int,int> > res;
	int final_positive = posit.front(); posit.pop();
	int cur = negat.front(); negat.pop();
	while( !posit.empty() ){
		int fr = posit.front(); posit.pop();
		res.pb( mp( cur, fr ) );
		cur = cur - fr;
	}
	res.pb( mp( final_positive, cur ) );
	cur = final_positive - cur;
	while( !negat.empty() ){
		int fr = negat.front(); negat.pop();
		res.pb( mp(cur,fr) );
		cur = cur-fr;
	}
	cout<<cur<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}