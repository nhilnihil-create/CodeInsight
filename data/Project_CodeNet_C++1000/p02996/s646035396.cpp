//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n;
	cin>>n;
	ll a,b;
	vector<pair<ll,ll>>v;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v.push_back({b,a});
	}

	sort(v.begin(),v.end());
	ll sum = 0;
	bool f = false;
	for(int i = 0;i<n;i++){
		sum += v[i].second;
		if(sum > v[i].first){
			f = true;
		}
	}

	if(f){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}


	

	return 0;
}