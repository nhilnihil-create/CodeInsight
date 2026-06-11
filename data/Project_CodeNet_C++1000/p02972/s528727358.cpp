#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
int a[N];
int boom[N];
vector <int> v;
int main()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    for(int i=n; i>=1; i--)
    {
        ll sum=0;
        for(int j=1; j*i<=n; j++)
        {
            sum+=boom[i*j];
        }
        sum%=2;
        if(a[i]!=sum) v.push_back(i),boom[i]=1;

    }
    cout<<v.size()<<endl;
    for(int i:v) cout<<i<<" ";
    return 0;
}
