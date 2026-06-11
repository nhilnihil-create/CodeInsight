//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,k;cin>>n>>k;
	vector<int> a(n-1),b(n-1);
	vector<vector<int>> e(n);
	for(int i=0;i<n-1;i++){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
		e[a[i]].push_back(b[i]);
		e[b[i]].push_back(a[i]);
	}
	vector<long long> c(n,-1),f(n,0);

	vector<pair<int,int>> s;
	for(int i=0;i<e[0].size();i++){
		s.push_back(make_pair(0,e[0][i]));
	}
	c[0]=k;
	while(s.size()){
		auto tempe=s.back();
		s.pop_back();
		if(c[tempe.second]!=-1)continue;
		c[tempe.second]=k-1-f[tempe.first];
		f[tempe.first]++;
		f[tempe.second]++;
//		cout<<tempe.first<<' '<<tempe.second<<' '<<c[tempe.second]<<endl;
		for(int i=0;i<e[tempe.second].size();i++){
			s.push_back(make_pair(tempe.second,e[tempe.second][i]));
		}
	}
	long long def=1;
	for(int i=0;i<9;i++)def*=10;
	def+=7;
	long long ans=1;
	for(int i=0;i<n;i++){
		ans*=c[i];
		ans%=def;
	}
	cout<<ans<<endl;
	return 0;
}