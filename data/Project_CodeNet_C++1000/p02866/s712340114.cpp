#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define eb emplace_back
#define mp make_pair
using namespace std;
const int MAX_N=1e5+10;
const int mod=998244353;
int n,x,d[MAX_N];
ll quick_mod(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=mod;
        (x*=x)%=mod,y>>=1;
    }
    return res;
}
int main(){
    cin>>n;
    bool flag=false;
    for(int i=0;i<n;i++){
        cin>>x;
        d[x]++;
        if(i==0){
            flag=(d[0]==1);
        }
    }
    ll ans=(d[0]==1&&flag);
    for(int i=1;i<MAX_N;i++){
        (ans*=quick_mod(d[i-1],d[i]))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}