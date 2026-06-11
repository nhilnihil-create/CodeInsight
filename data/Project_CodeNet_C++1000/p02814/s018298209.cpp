#include<bits/stdc++.h>
using namespace std;
long long n,m,cd=1,c=1;
int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
int main()
{
  	cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++)
    {
        long long a; 
      	cin>>a;
        cd=lcm(cd,a);
        c=lcm(c,a/2);
        int tmp=0;
        while(a%2==0)
		{
            tmp++;
            a/=2;
        }
        if(i==1)
          	x=tmp;
        else 
			if(x!=tmp||c>m)
	        {
	            cout<<0<<endl;
	            exit(0);
	        }
    }
    if(m<c)
      	cout<<0;
    else 
      	cout<<((m-c)/cd)+1;
}