#include<bits/stdc++.h>
using namespace std;

main(){
	string s,t; cin>>s>>t;
	
	int ans=s.length();
	for(int i=0; i<=s.length()-t.length(); i++){
		int k=i, cnt=0;
		for(int j=0; j<t.length(); j++,k++){
			if(t[j] != s[k]){
				cnt++;
			}
		}
		ans = min(ans,cnt);
	}
	cout<<ans;
}