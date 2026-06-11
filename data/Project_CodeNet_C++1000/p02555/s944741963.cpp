#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int Mod=1e9+7;
int s,f[2001];
int main()
{
	cin>>s;
	f[3]=1;
	for(int i=4;i<=s;i++)
		f[i]=(f[i-3]+f[i-1])%Mod;
	cout<<f[s];
}