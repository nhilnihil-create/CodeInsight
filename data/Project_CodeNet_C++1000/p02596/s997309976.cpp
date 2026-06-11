#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =1e5+10;
const int mod=1e9+7;




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>k;
    ll sum=7;
    for(int i=1;i<1e7;i++)
    {
        if(sum%k==0)
        {
            cout<<i<<'\n';
            return 0;
        }
        sum*=10;
        sum+=7;
        sum%=k;
    }
    cout<<-1<<'\n';





}
