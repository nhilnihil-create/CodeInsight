#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>>v(n);
	for(int i=0;i<n;i++){
		int x,l;
		cin>>x>>l;
		v[i]={x+l,x-l};
	}
	sort(v.begin(),v.end());
		int ans=0;
		int cnt=INT_MIN;
		for(int i=0;i<n;i++){
			if(v[i].second>=cnt){
				ans++;
				cnt=v[i].first;
			}
		}
		cout<<ans<<endl;
		return 0;
}