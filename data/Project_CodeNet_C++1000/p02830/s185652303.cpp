#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int main(){
	int n;cin>>n;
	string s,t;cin>>s>>t;
	string res="";
	for(int i=0;i<n;i++){
		res+=s[i];res+=t[i];
	}	
	cout<<res;
	return 0;
}