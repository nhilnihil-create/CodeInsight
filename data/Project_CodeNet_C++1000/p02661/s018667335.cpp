#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> v,vv;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back(x);
		vv.push_back(y);
	}
	
	sort(v.begin(),v.end());
	sort(vv.begin(),vv.end());
	
	if(n&1){
		cout<< vv[n/2] - v[n/2]+1;
	}
	else{
		int mn = v[n/2-1] + v[n/2];
		int mx = vv[n/2-1] + vv[n/2];
		cout<<mx - mn + 1;
	}
	return 0;
}
