#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
int main()
{
    int n,m;
    cin>>n>>m;
    int sum=0;
    for(int i=0,x;i<m;i++)cin>>x,sum+=x;
    if(sum<=n)cout<<n-sum<<endl;
    else cout<<-1<<endl;
}
