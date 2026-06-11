#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define FI first
#define SE second
#define ULL unsigned long long
#define endl '\n'
#define c(x) cout<<x<<endl
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
map<int,int>num;
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int len=s.length();
	int ans=0;
	int tmp=0,p=1;
	num[0]++;
	for(int i=len-1;i>=0;i--){
		tmp=(tmp+(s[i]-'0')*p)%2019;
		tmp=tmp%2019;
		ans+=num[tmp]++;
		p=p*10%2019;
		//cout<<tmp<<endl;
	}
	c(ans);
 	return 0;
}





