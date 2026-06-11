#include<bits/stdc++.h>
using namespace std;

int main(){
int n,x[100],y[100];
double ans1=0,ans2=0,ans4=0,ans3=0;
long z=0;
cin>>n;
for(int i=0;i<n;i++)
	{cin>>x[i];
	}
for(int i=0;i<n;i++)
	{cin>>y[i];
	}
for(int i=0;i<n;i++)
	{
	if(x[i]-y[i]<0) {y[i]*=-1;x[i]*=-1;}
	ans1+=x[i]-y[i];
	}
for(int i=0;i<n;i++)
	{z+=(x[i]-y[i])*(x[i]-y[i]);
	}
ans2=sqrt(z);
z=0;
for(int i=0;i<n;i++)
	{z+=pow(x[i]-y[i],3);
	}
ans4=pow(z,1.0/3);
z=0;
for(int i=0;i<n;i++)
	{z=x[i]-y[i];
	if(ans3<z) ans3=z;
	z=0;
	}
printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n",ans1,ans2,ans4,ans3);
return 0;
}
