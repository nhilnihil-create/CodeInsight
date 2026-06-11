/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

ll d[10000006];

int main()
{
    for(int i=1;i<=10000000;i++) d[i]=1;

    for(int i=2;i<=10000000;i++){
        for(int j=i;j<=10000000;j+=i){
            d[j]++;
        }
    }

    ll n;
    cin>>n;

    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=(i*d[i]);
    }
    cout<<sum<<endl;

    return 0;
}


