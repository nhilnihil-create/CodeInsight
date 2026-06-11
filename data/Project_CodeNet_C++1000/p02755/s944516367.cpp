#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    int ans=-1;
    for(int i=0; i<=1000; i++)
    {
    	int var1=i*8/100;
    	int var2=i*10/100;
    	if(var1==a && var2==b)
    	{
    		ans=i;
    		break;
		}
	}
	cout<<ans;
	return 0;
}