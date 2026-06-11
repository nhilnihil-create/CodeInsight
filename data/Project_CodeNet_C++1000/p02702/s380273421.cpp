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
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
const int maxn=202000;
int a[maxn],b[maxn];
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	string s;
	ll sum=0;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		int tmp=s[i]-'0';
		b[tmp]=1;
		for(int j=0;j<2019;j++){
			b[(j*10+tmp)%2019]+=a[j];
		}
		for(int j=0;j<2019;j++){
			a[j]=b[j];
			b[j]=0;
		}
		sum+=a[0];
	}
	
	
	cout<<sum<<endl;
 	return 0;
}





