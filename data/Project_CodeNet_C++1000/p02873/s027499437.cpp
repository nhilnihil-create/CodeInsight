#include <bits/stdc++.h>
using namespace std;

int main() {
	long n,i,cur;
	string s;
	cin >> s;
	n=s.size();
	vector<long> ans(n+1,0);
	for(i=0; i<n; i++){
		if(s[i]=='<'){
			ans[i+1]=ans[i]+1;
		}
	}
	
	for(i=0; i<n; i++){
		if(s[n-1-i]=='>'){
			ans[n-1-i]=max(ans[n-i]+1,ans[n-1-i]);
		}
	}
	
	cur=0;
	for(i=0; i<n+1; i++){
		cur+=ans[i];
	}
	cout << cur << endl;
	return 0;
}