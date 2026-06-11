#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7; 
int main(){
	IOS;
	string s,t;
	cin>>s>>t;
	int n=s.length();
	int m=t.length();
	int ans=1002;
	for(int i=0;i<=n-m;i++){
		int temp=0;
		for(int j=0;j<m;j++){
			if(s[i+j]!=t[j]) temp++;
		}
		ans=min(ans,temp);
	}
	cout<<ans;
}