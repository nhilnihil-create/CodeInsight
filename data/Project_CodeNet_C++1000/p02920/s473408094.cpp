#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	multiset<int> ms;
	vector<int> v;
	for(int i=0;i<(1<<n);i++){
		int x;
		cin>>x;
		ms.insert(x);
	}
	multiset<int>::iterator it = ms.end();
	--it;
	v.pb(*it);
	ms.erase(it);
	//it = ms.begin(); while( it != ms.end() ){ cout<<*it<<" "; it++; } cout<<endl;
	for(int k=1;k<=n;k++){
		int times = 1 << (k-1);
		for(int i=0; i<times;i++){
			int cur = v[i];
			it = ms.lower_bound(cur);
			if( it == ms.begin() && *it >= cur ){
				cout<<"No"<<endl;
				return 0;
			}
			else if( it == ms.end() || *it >= cur){
				--it;
				v.pb(*it);
				//cout<<*it<<endl;
				ms.erase(it);
			}
			else{
				v.pb(*it);
				//cout<<*it<<endl;
				ms.erase(it);
			}
		}
		sort( v.begin(), v.end(), greater<int>() );
	}
	cout<<"Yes"<<endl;
	return 0;
}