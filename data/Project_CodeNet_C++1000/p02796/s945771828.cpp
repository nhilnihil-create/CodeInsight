#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int n;
	cin>>n;
	vector<pair<long long,long long>> p(n);
	for(int i=0;i<n;i++){
		long long x,l;
		cin>>x>>l;

		p.at(i).first=x+l;
		p.at(i).second=x-l;
	}

	sort(p.begin(),p.end());

	long long ans=0;
	long long now=inf*-1;

	for(auto a:p){
		if(a.second>=now){
			ans++;
			now=a.first;
		}
	}

	cout<<ans<<endl;

	return 0;
}
