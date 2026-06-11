#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const long long Mod=1e9+7;
long long n,a=1,b=1,c=1;
int main() 
{
	cin>>n;
	while(n--)
	a=a*10%Mod,b=b*9%Mod,c=c*8%Mod;
	cout<<(((a+c)%Mod+Mod-b)%Mod+Mod-b)%Mod<<endl;
}