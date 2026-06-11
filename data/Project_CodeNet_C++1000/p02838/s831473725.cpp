#include<iostream>
#include<vector>
#define lli long long int
#define pb push_back
using namespace std;


int main()
{
    lli n;
    lli p =  (lli)(1e9+7);
    cin>>n;
    vector<lli>arr(n+1);
    for(lli i=1;i<=n;i++)  cin>>arr[i];
    
    vector<lli>set(62,0);
    vector<lli>unset(62,0);

    for(lli i=0;i<62;i++)
    {
        for(lli j=1;j<=n;j++)
        {
            if((arr[j]&(1ll<<i))>0) set[i]++;
            else unset[i]++;
        }
    }
    lli ans=0;
    lli mul;
    lli mul2;
    lli co;
    for(int i=0;i<62;i++)
    {
        mul = (set[i]%p * unset[i]%p)%p;
        co = (1ll<<i)%p;
        mul2 = (mul%p * co%p)%p;
        ans = (ans%p + mul2%p)%p;
    }
    cout<<ans<<endl;
    
}
