/* Ahmed Maher ( Acro_14 ) */
#include <bits/stdc++.h>
typedef long long ll;
const ll oo = 0x3f3f3f3f;
int const N = 1e7;
using namespace std;
//string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//string BN(ll x){bool f=0;string Bn;int i=62;while(i--){if ((ll)x & (1LL << i)){Bn+='1';f=1;}else{if(f)Bn+='0';}}return Bn;}//Decimal to Binary converter
int main()
{
    ll n,i,sum=0,cur;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cur=n/i;
        sum+=i*(cur*(cur+1));
    }
    cout<<sum/2;
}

//       int anss[t+1];
//            anss[j]=ans;
//     for(int j=1;j<=t;j++) printf("Case %d: %d\n",j,anss[j]);
