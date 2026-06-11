/* author   : mpily :-()
title : Competing.cpp
time :Sat Apr 11 11:13:36 2020

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>S(n);
	vector<int>T(m);
	for(int i = 0; i < n;++i){
		cin>>S[i];
	}
	for(int i = 0; i < m ;++i){
		cin>>T[i];
	}
	vector<long long>canSat(n+1);
	canSat[0] = 1;
	for(int i = 0; i < m; ++i){
		long long psum = 1;
		for(int j = 1; j <= n; ++j){
			long long tmp = psum+canSat[j];
			tmp%=mod;
			if(S[j-1] == T[i]){
				canSat[j]+=psum;
				canSat[j]%=mod;
			}
			psum = tmp;
		}
	}
	long long ans = 0;
	for(auto a : canSat){
		ans+=a;
		ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}
