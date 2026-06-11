/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
lli modexp(lli x, lli y)
{
    x%=MOD;
    lli ans=1ll;
    while(y>0ll)
    {
        if(y&1ll)
            ans=(ans*x)%MOD;
        x=(x*x)%MOD;
        y>>=1ll;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    lli x=0ll,res=0ll;
    for(int i=0;i<n;++i)
    {
        int len=n-i-1;
        if(s[i]=='1')
        {
            res+=(modexp(2ll,x)*modexp(3ll,len))%MOD;
            ++x;
        }
    }
    res+=modexp(2ll,x);
    cout<<res%MOD<<endl;
}