#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=0,last=0;
	rep(i,n){
		if(last!=1 || s[i]!=s[i-1]){
			ans++;
			last=1;
		}
		else{
			if(i<n-1) ans++;
			last=2;
			i++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
