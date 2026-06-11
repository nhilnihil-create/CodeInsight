#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
inline __int128 read()
{
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}

int main()
{
	ll t1,t2,a1,a2,b1,b2;//cin>>t1>>t2>>a1>>a2>>b1>>b2;
	t1=read();t2=read();a1=read();a2=read();b1=read();b2=read();
	ll v1=a1-b1;ll v2=a2-b2;
	if(v1*v2>0)
	{
		cout<<0<<endl;
		return 0;
	}
	else
	{
		ll x1=v1*t1,x2=v2*t2;
		if(x1>0&&(x1+x2)>0)
		{
			cout<<0<<endl;
			return 0;
		}
		else if(x1>0&&(x1+x2)==0)
		{
			cout<<"infinity"<<endl;
			return 0;
		}
		else if(x1>0&&(x1+x2)<0)
		{
			ll res=(-x1-x2);
			ll ans=x1/res;
			if(x1%res!=0) write(2ll*(ans)+1ll); 
			else write(2ll*(ans)); 
			return 0;
		}
		else if(x1<0&&(x1+x2)<0)
		{
			cout<<0<<endl;
			return 0;
		}
		else if(x1<0&&(x1+x2)==0)
		{
			cout<<"infinity"<<endl;
			return 0;
		}
		else if(x1<0&&(x1+x2)>0)
		{
			ll xx=-x1;
			if(xx%(x1+x2)!=0)write(2ll*(xx/(x1+x2))+1ll); 
			else write(2ll*(xx/(x1+x2))); 
			return 0;
		} 
		else while(1);
	}
	return 0;
 } 