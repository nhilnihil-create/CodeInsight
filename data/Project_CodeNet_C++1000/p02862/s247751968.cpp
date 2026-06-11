#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const ll MAX=2000000;
const ll MOD=1000000007;
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int r){
    if(n<r) return 0;
    if(n<0 | r<0) return 0;
    return fac[n]*(finv[n-r]*finv[r]%MOD)%MOD;
}

int main(){
    COMinit();
    int x,y;cin>>x>>y;
    if(2*x-y>=0&&(2*x-y)%3==0&&2*y-x>=0&&(2*y-x)%3==0){
        int a=(2*y-x)/3;int b=(2*x-y)/3;
        int n=a+b;int r=min(a,b);
        cout<<COM(n,r)<<endl;
    }
    else cout<<0<<endl;
}