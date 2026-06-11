#include<bits/stdc++.h>

using namespace std;

int n,a,d,t[1000003],zzs=-(1<<30);

int sq(int x,int y)
{
    if(!y) 
		return x;
    return sq(y,x%y);
}
void fj(int x)
{
    for(int i=2;i*i<=x;)
	{
        if(!(x%i))
		{
            t[i]++;
            while(!(x%i)) 
				x/=i;
        }
        else 
			i++;
    }
    if(x>1) 
		t[x]++;
}
int main()
{
    scanf("%d%d",&n,&a);
    d=a;
    for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
        if(zzs<a) 
			zzs=a;
        d=sq(d,a);
        fj(a);
    }
    if(d==1)
	{
        for(int i=2;i<=zzs;i++)
        {
        	if(t[i]>1) 
			{
				printf("setwise coprime\n");
				return 0;
			}
		}
        printf("pairwise coprime\n");
        return 0;
    }
    else
    {
    	printf("not coprime\n");
    	return 0;
	}
    return 0;
}