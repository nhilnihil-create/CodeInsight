//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int n,k;cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> v;
	int ans=1;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	for(int i=1;i*i<=sum;i++){
		if(sum%i)continue;
		v.push_back(i);
	}
	int vs=v.size();
	for(int i=0;i<vs;i++){
		v.push_back(sum/v[i]);
	}
	for(int i=0;i<v.size();i++){;
		vector<int> p,m;
		for(int j=0;j<n;j++){
			p.push_back(v[i]-(a[j]%v[i]));
			m.push_back(a[j]%v[i]);
		}
		sort(p.begin(),p.end());
		sort(m.begin(),m.end());
		for(int j=1;j<n;j++){
			p[j]+=p[j-1];
			m[j]+=m[j-1];
		}
		for(int j=0;j<n-1;j++){
			if(p[j]==m[n-2-j]){
				if(p[j]<=k){
					ans=max(ans,v[i]);
				}
				break;
			}
			if(j==n-2){
//				for(int k=0;k<n;k++){
//					cout<<p[k]<<' ';
//				}cout<<endl;
//				for(int k=0;k<n;k++){
//					cout<<m[k]<<' ';
//				}cout<<endl;
				ans=max(ans,v[i]);
			}
		}

	}
	cout<<ans<<endl;
	return 0;
}
