#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#include<iostream>
#define rep1(i,a) for(i=1;i<=a;i++) 
#define rep2(j,a) for(j=i+1;j<=n;j++)
#define rep3(k,a) for(k=j+1;k<=n;k++)
using namespace std;
int main(void)
{
	int n,x,sum;
	int i,j,k;
    while(1){
        cin>>n>>x;
        if(n==0&&x==0)break;
        rep1(i,n)rep2(j,n)rep3(k,n){
			if(i+j+k==x)sum+=1;
        }
        cout<<sum<<endl;
		sum=0;
    }
return 0;
}