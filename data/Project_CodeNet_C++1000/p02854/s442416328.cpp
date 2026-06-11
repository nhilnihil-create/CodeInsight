#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,sum3=0;
    cin>>n;
    vector<ll>v;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum3+=x;
        v.push_back(x);
    }
    ll sum1=v[0];
    ll sum2=abs(sum3-sum1);
    ll diff=abs(sum1-sum2);
    ll ans=diff;
    for(int i=1;i<n-1;i++)
    {
        sum1+=v[i];
        sum2-=v[i];
        diff=abs(sum1-sum2);
        if(diff<ans)
        ans=diff;
    }
    cout<<ans<<endl;
    return 0;
}
