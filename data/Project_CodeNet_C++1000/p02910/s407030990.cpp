/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    bool flag=false;
    for(int i=0;i<s.length();++i)
    {
    	if(i%2==0)
    	{
    		if(s[i]=='L')
    		{
    			flag=true;break;
    		}
    	}
    	else
    	{
    		if(s[i]=='R')
    		{
    			flag=true;break;
    		}
    	}
    }
    cout<<(flag?"No":"Yes")<<endl;
}