/* Ahmed Maher ( Acro_14 ) */
#include <bits/stdc++.h>
typedef long long ll;
const ll oo = 0x3f3f3f3f;
int const N = 1e5+5;
using namespace std;
//string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//string BN(ll x){bool f=0;string Bn;int i=62;while(i--){if ((ll)x & (1LL << i)){Bn+='1';f=1;}else{if(f)Bn+='0';}}return Bn;}//Decimal to Binary converter
int main()
{
    int n;
    ll ans=0;
    cin>>n;
    int a[N]={0},b[N]={0};
    for(int i=0;i<=n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        ll dec = min (b[i],a[i]);
        ans +=dec;
        b[i]-=dec;
        dec = min (b[i],a[i+1]);
        a[i+1]-=dec;
        ans+=dec;
    }
    cout<<ans;
}

//       int anss[t+1];
//            anss[j]=ans;
//     for(int j=1;j<=t;j++) printf("Case %d: %d\n",j,anss[j]);
