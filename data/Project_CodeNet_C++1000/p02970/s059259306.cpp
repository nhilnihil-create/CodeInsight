#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    int n,d,ans;
    cin>>n>>d;
    ans=n/(d*2+1);
    if(n%(d*2+1)!=0) ans++;
    cout<<ans;
}