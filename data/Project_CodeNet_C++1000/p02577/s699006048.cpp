#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	long long sum=0;
	for(int i=0;i<s.length();i++) sum+=int(s[i])-48;
	(sum%9==0)?cout<<"Yes":cout<<"No";
	return 0;
}