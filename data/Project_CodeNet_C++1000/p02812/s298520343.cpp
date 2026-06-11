#include<bits/stdc++.h>
using namespace std;
int f(int curr,string&a){
	if(curr>=a.length()-2) return 0;
	if(a[curr]!='A') return f(curr+1,a);
	if(a[curr+1]=='B' && a[curr+2]=='C') return 1+f(curr+3,a);
	return f(curr+1,a);
}
int main(){
	int n;
	string s;
	cin>>n>>s;
	cout<<f(0,s);
}