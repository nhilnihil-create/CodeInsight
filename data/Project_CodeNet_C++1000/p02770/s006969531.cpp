#include <bits/stdc++.h>
//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//~ using namespace __gnu_pbds; 
#define mp make_pair
#define endl '\n'
typedef long long ll;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=2e5+5;
const int mod=1e9+7;	
const ll oo=1e18+5;

//~ typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vector<int> d;
int k;

void solve(){
	int n,x,m;
	cin>>n>>x>>m;
	vector<int> rem(k);
	for(int i=0;i<k;++i){
		rem[i]=d[i]%m;
	}
	int tot=n-1;
	int num=(n-1)/k;
	int add=(n-1)%k;
	int equal=0;
	// count equal
	for(int i=0;i<k;++i){
		if(!rem[i]) ++equal;
	}
	equal*=num;
	for(int i=0;i<add;++i){
		if(!rem[i]) ++equal;
	}
	//~ cout<<equal<<endl;
	ll sum=0;
	for(int i=0;i<k;++i){
		sum+=rem[i];
	}
	sum*=num;
	for(int i=0;i<add;++i){
		sum+=rem[i];
	}	
	sum+=x;
	int greater=(sum/m)-(x/m);
	tot-=(greater+equal);
	cout<<tot<<endl;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int q;
	cin>>k>>q;
	d.resize(k);
	for(int& x:d) cin>>x;
	while(q--){
		solve();
	}
	return 0;	
}
