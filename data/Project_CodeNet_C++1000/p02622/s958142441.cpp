#include"bits/stdc++.h"
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
	string s;
	string t;
	int cnt=0;
	cin>>s>>t;

	for(int i=0;i<s.size();i++){
		if(s[i]==t[i]);
		else cnt++;
	}

	cout<<cnt<<endl;

	return 0;
}