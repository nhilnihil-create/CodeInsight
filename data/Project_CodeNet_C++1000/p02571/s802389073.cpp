#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s,t;
	cin>>s>>t;
	//cout<<s<<" "<<t;

	int n = t.size();
	int m = s.size();
	int mn = INT_MAX;
	for(int i=0;i<=m-n;i++){
		int cnt =0;	
		for(int j=0;j<n;j++){
			if(t[j]!=s[j+i])
				cnt++;
		}
		mn = min(mn,cnt);
	}
	cout<<mn<<endl;
}