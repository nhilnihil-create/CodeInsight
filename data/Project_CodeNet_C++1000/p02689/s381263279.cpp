#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#define mp make_pair
#define pb push_back
#define mem(i,a) memset(i,a,sizeof(i))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int DMAX=500010+5;
const int MOD=1000000000+7;
template<class T> inline void read(T &x){
    x=0;
    T f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9' && ch>='0'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    x*=f;
}
ll n,m;
ll a[DMAX];
ll ans=0;
bool b[DMAX];
int main(){
    mem(b,1);
    read(n),read(m);
    for(ll i=1;i<=n;i++){
        read(a[i]);
    }
    ll x,y;
    for(ll i=1;i<=m;i++){
        read(x),read(y);
        if(a[x]>a[y]){
            b[y]=0;
        }
        if(a[x]<a[y]){
            b[x]=0;
        }
        if(a[x]==a[y]){
            b[x]=b[y]=0;
        }
    }
    for(ll i=1;i<=n;i++){
        if(b[i])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}