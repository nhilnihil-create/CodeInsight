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
    int n=0,k=0,ct=0,res=0;string s;char pre='$';
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<s.length();++i)
    {
    	if(s[i]!=pre)
    	{
    		pre=s[i];
    		++ct;
    	}
    	if(i-1>=0&&s[i]=='L'&&s[i-1]=='L')
    		++res;
    	if(i+1<s.length()&&s[i]=='R'&&s[i+1]=='R')
    		++res;
    }
    ct=(ct-1)/2;
    if(k>ct)
    	res=n-1;
    else
    	res+=2*k;
    cout<<res<<endl;
}