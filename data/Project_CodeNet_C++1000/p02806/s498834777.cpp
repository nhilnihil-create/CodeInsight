#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int n,a[55],ss=0;
string s[55]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i]>>a[i];
	string t;
	cin>>t;
	for(int i=n;i>=1;i--){
		if(s[i]==t)return cout<<ss<<endl,0;
		ss+=a[i];
	}
}