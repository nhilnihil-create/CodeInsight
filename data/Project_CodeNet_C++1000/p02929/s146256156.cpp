#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pb push_back

#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int N=((1e9)+7);

signed main()
{
    int n;cin>>n;
    int fact=1;
    for(int i=2;i<=n;++i){fact*=i;fact%=N;}
    string str;cin>>str;
    int forw=0;
    int ans=1;
    int prev=1;
    for (int i = 0; i < 2*n; ++i)
    {
    	/* code */
    	if(forw==0)
    	{
    		if(str[i]=='B'){++forw;prev=1;}
    		else
    		{
    			cout<<0;return 0;
    		}
    	}
    	else
    	{
    		prev=((str[i]!=str[i-1]?1:-1)*prev);
    		if(prev==1)
   			{
   				++forw;
   			}
   			else
   			{
   				if(forw==0){cout<<0;return 0;}
    			ans*=forw;ans%=N;
    			--forw;
    		}
    	}
    }
    if(forw==0)
    {
    	cout<<((ans*fact)%N);return 0;
    }
    else
    {
    	cout<<0;return 0;
    }
}