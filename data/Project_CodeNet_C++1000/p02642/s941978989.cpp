#include <bits/stdc++.h>
using namespace std;
int exist[1000005];
int max1;
int min1=0x3f3f3f3f;
int end1;
bool flag[1000005];
void sieve()
{
    for(int i=min1;i<=max1;i++)
    {
    	if(exist[i]==1)
        {
            for(int j=2*i;j<=max1;j+=i)
            {
                if(exist[j]&&flag[j]==0)
                {
                    exist[j]--;
                    end1--;
                }
            }
        }
    }
}
int x;
int main() 
{
    int n;cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>x;
        exist[x]++;
        max1=max(max1,x);
        min1=min(min1,x);
    }
    for(int i=min1;i<=max1;i++)
    {
    	if(exist[i]==1)
    	{
    		end1++;
		}
		else if(exist[i]>1)
		{
			exist[i]=1;
			flag[i]=1;
		}
	}
    sieve();
    cout<<end1;
}


