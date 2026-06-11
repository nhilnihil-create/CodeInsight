#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=4e3+10,M=1e9+7;
int fat[mxN],inv[mxN];
int n,k,temp;
int mod(int a,int M){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b,int M){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a,M);
    int t=exp(a,b/2,M);
    if(b&1)return mod(a*mod(t*t,M),M);
    return mod(t*t,M);
}
int C(int n,int k){
    if(n-k<0)return 0;
    return mod(fat[n]*mod(inv[k]*inv[n-k],M),M);
}

// LONG LONG CASE
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fat[0]=inv[0]=1LL;
    for(int i=1;i<=mxN;i++){
        fat[i]=mod(fat[i-1]*i,M);
    }
    inv[mxN-1]=exp(fat[mxN-1],M-2,M);
    for(int i=mxN-2;i>=1;i--){
        inv[i]=mod(inv[i+1]*(i+1),M);
    }
    for(int i=1;i<=k;i++){
        cout<<mod(C(k-1,k-i)*C(n-k+1,i),M)<<"\n";       
    }
}