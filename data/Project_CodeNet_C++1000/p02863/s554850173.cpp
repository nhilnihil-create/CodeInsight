//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n,t;cin>>n>>t;
	vector<int> a(n),b(n);
	vector<pair<int,int>> p;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		p.push_back(make_pair(a[i],b[i]));
	}
	sort(p.begin(),p.end());
	for(int i=0;i<n;i++){
		a[i]=p[i].first;
		b[i]=p[i].second;
	}

	if(t==1){
		int maxb=0;
		for(int i=0;i<n;i++){
			maxb=max(maxb,b[i]);
		}
		cout<<maxb<<endl;
		return 0;
	}
	vector<vector<int>> v(t+1,vector<int>(n+1,0));
	for(int i=0;i<=t-1;i++){
		if(i>=a[0]){
			v[i][0]=b[0];
		}
		for(int j=1;j<n;j++){
			if(i>=a[j]){
				v[i][j]=v[i-a[j]][j-1]+b[j];
			}
			v[i][j]=max(v[i][j],v[i][j-1]);
		}
	}
	v[t][0]=b[0];
	int ans=b[0];
	for(int i=1;i<n;i++){
		v[t][i]=max(v[t][i-1],v[t-1][i-1]+b[i]);
		ans=max(ans,v[t][i]);
	}
	cout<<ans<<endl;
	return 0;
}