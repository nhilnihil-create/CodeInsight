#include<bits/stdc++.h>
using namespace std;

int main(){
  double b,s[1000],n,x;
  while(1)
  {
    cin>>n;
    if(n==0) break;
    x=0;
    for(int i=0; i<n;i++)
	{
          cin>>s[i];
	  x+=s[i];
	}
    double m=x/n;
    b=0;
    for(int i=0; i<n; i++)
	{
          b+=(s[i]-m)*(s[i]-m);
	}
     printf("%.8lf\n",sqrt(b/n));
}
return 0;
}
