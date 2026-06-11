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

int main()
{
    ll a[20]={0},b[20]={0};
    ll sum=0,last=1,p=1;
    for(int i=1;i<=11;i++){
        p=p*26;
        sum+=p;
        a[i]=last; b[i]=sum;
        last=sum+1;
    }

    ll n;
    cin>>n;

    int len=0;
    for(int i=1;i<=11;i++){
        if(a[i]<=n && b[i]>=n){
            len=i;
            break;
        }
    }

    string ans="";
    for(int i=1;i<=len;i++){
        n-=1;
        int r=n%26;
        ans+=(r+97);
        n/=26;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

    return 0;
}


