#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main() {
	// your code goes here
	int n,ans=0;
	cin>>n;
	string s[50];
	string X;
	int t[50];
	for(int i=0;i<n;i++){
		cin>>s[i]>>t[i];
	}
	cin>>X;
	for(int i=n-1;i>=0;i--){
		if(s[i]==X)
		break;
		ans+=t[i];
	}
	cout<<ans<<endl;
	return 0;
}