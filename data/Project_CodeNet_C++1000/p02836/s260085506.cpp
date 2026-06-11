
// Problem : B - Palindrome-philia
// Contest : AtCoder - AtCoder Beginner Contest 147
// URL : https://atcoder.jp/contests/abc147/tasks/abc147_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
using namespace std;
int main()
{
	lli t=0,a,i;
	string s;
	cin>>s;
	a=s.length();
	for(i=0;i<s.length()/2;i++){
		if(s[i]!=s[a-1-i])
		t++;
	}
	cout<<t;
	
	
	return 0;
}