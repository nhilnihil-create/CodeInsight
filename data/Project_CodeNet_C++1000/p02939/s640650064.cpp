#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int



main() {
	string s;
	cin>>s;
	int last=2;
	int ans=0;
	int i=0;
	while(i<s.size()){
		if(last==2){
			i++;
			last=1;
			ans++;
			continue;
		}
		if(last==1){
			if(s[i]==s[i-1] && i==s.size()-1){
				i++;
				i++;
				continue;
			}
			if(s[i]==s[i-1]){
				last=2;
				i++;
				i++;
				ans++;
				continue;
			}
			else{
				last=1;
				i++;
				ans++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}