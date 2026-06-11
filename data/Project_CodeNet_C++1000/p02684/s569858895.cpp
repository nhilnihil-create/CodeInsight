#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
vector<ll> v;
int boom[N];
int a[N];
int main()
{
    ll n,k;cin>>n>>k;k++;
    for(int i=1;i<=n;i++) cin>>a[i];
    v.push_back(1);
    boom[1]=1;
    int i=1;
    while(!boom[a[i]])
    {
        v.push_back(a[i]);
        boom[a[i]]=1;
        i=a[i];
    }
    int t=inf;
    for(int j=0;j<v.size();j++)
    {
        if(v[j]==a[i])
        {
            t=j;break;
        }
    }
    int len=v.size()-t;
    if(k<=t) cout<<v[k-1]<<endl;
    else
    {
        cout<<v[(t+(((k-t)%len==0)?len:((k-t)%len))-1)];
    }
    return 0;
}
