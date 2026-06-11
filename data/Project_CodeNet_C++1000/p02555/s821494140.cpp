#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
#define lson (rt<< 1)
#define rson (rt<< 1 | 1)
#define gmid ((l+r)>> 1 )
using namespace std;

const int p=1e9+7;

int f[2002];

int main()
{
	int n;
	cin>>n;  
    f[0]=1;
    for(int i=0;i<=n;++i)
      for(int j=3;j+i<=n;++j)
        f[i+j]=(f[i+j]+f[i])%p; 
	cout<<f[n]<<endl;   
}
