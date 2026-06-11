#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	int m;cin>>m;
	ll ds=0,l=0;
	for(int i=0;i<m;i++){
		ll d,c;cin>>d>>c;
		l+=c;
		ds+=d*c;
	}
	ll res=l-1LL+(ds-1LL)/9LL;
	cout<<res<<endl;
}	
