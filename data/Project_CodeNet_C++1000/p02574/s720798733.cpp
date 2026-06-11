#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll n,cnt=0;
ll a[N],f[N];
bool prime[N];
string s1,s2;
int main() {
 //   freopen("../in.in", "r", stdin);
//    freopen("../out.out","w",stdout);
    ios::sync_with_stdio(false);
    ll t, i, j = 0;
    ll m, x, y,k;
    memset(prime,true,sizeof(prime));
    for(i=2;i<=N;i++){
        if(prime[i]){
            for(j=i*2;j<=N;j+=i) prime[j]=false;
        }
    }
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>x;
        if(prime[x]) f[x]++;
        else{
            for(j=2;j<=sqrt(x);j++){
                if(x%j==0) f[j]++;
                while(x%j==0) x/=j;
            }
            f[x]++;
        }
    }
    bool f1=true,f2=true;
    for(i=2;i<=N;i++){
        if(f[i]>1) f1=false;
        if(f[i]>=n) f2=false;
    }
    if(f1) cout<<"pairwise coprime";
    else if(f2) cout<<"setwise coprime";
    else cout<<"not coprime";
    cout<<endl;
    return 0;
}