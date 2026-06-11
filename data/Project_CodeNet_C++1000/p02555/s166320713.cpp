#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll a[2005];
void pre(){
    a[0]=a[1]=a[2]=1;
    for(int i=3;i<=2000;i++) a[i]=(a[i-3]+a[i-1])%mod;
}
int main()
{
    pre();
    int n;
    cin>>n;
    if(n<3) cout<<0;
    else cout<<a[n-3];
    return 0;
}