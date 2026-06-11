//============================================================================
// Name        : f.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n;cin>>n;
	ll d,a;cin>>d>>a;
	vector<ll> x(n),h(n);
	vector<pair<ll,ll>> p(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>h[i];
		p[i].first=x[i];
		p[i].second=h[i];
	}
	sort(p.begin(),p.end());
	for(int i=0;i<n;i++){
		x[i]=p[i].first;
		h[i]=p[i].second;
	}
	queue<pair<ll,ll>> q;
	ll sum=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		while(1){
			if(q.size()==0)break;
			if(x[i]-q.front().first<=(2*d))break;
			sum-=q.front().second*a;
			q.pop();
		}
//		cout<<i<<' '<<sum<<endl;
		ll b=0;
		if(h[i]-sum>0){
			b=(h[i]-sum-1)/a+1;
		}
		sum+=b*a;
		ans+=b;
		q.push(make_pair(x[i],b));
//		cout<<i<<' '<<b<<endl;
	}
	cout<<ans<<endl;
	return 0;
}