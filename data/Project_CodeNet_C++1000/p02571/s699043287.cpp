#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	cin>>s>>t;
	int n=t.size(),p=s.size(),mini=INT_MAX;
	for(int i=0;i<=p-n;i++){
		string st=s.substr(i,n);
		int s=0;
		for(int h=0;h<n;h++){
			if(st[h]!=t[h])s++;
		}
		mini=min(s,mini);
	}
	cout<<mini;
	return 0;
}