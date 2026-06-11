#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	string S, T;
	cin>>S>>T;
	int n = S.length();
	int m = T.length();
	int ans = 10000;
	for (int i=0; i<=n-m; i++){
		int count = 0;
		for (int j=0; j<m; j++){
			if(S[j + i]  != T[j])	count++;
		}
		ans = min(ans, count);
	}
	cout<<ans;
}