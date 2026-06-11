#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	s.push_back('#');
	int n=s.size();
	int ans=0, cur=0;
	vector<int>v;
	if(s[0]=='>') v.push_back(0);
	for(int i=0;i<n;i++){
		if(i==0) cur++;
		else if(s[i]!=s[i-1]){
			v.push_back(cur);
			ans+=cur*(cur-1)/2;
			cur=1;
		}
		else cur++;
	}
	if(s[n-2]=='<') v.push_back(0);
	//if(s[0]=='<'){
		for(int i=0;i<v.size()-1;i+=2){
			ans+=max(v[i], v[i+1]);
		}
	//}
	cout<<ans;
}