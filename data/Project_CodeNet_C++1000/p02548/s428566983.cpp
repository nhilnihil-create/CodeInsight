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

int a[1000005];

int main()
{
    for(int i=1;i<=1e6;i++) a[i]=1;
    for(int i=2;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i){
            a[j]++;
        }
    }

    int n;
    cin>>n;
    ll cnt=0;
    for(int i=1;i<n;i++){
        int x=n-i;
        //cout<<n<<" "<<i<<" "<<x<<" "<<a[x]<<endl;
        cnt+=(a[x]);
    }
    cout<<cnt<<endl;

    return 0;
}


