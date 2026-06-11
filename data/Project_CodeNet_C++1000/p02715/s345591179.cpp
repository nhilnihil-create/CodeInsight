#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e5+10,M=1e9+7;
int n,k;
int mod(int a,int M){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b,int M){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a,M);

    int t=exp(a,b/2,M);
    if(b&1)return mod(a*mod(t*t,M),M);
    return mod(t*t,M);
}
int v[mxN];
int resp;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    
    for(int x=k;x>=1;x--){
        int temp=k/x;
        temp=exp(temp,n,M);
        for(int i=2*x;i<=k;i+=x){
            temp-=v[i];
        }
        v[x]=temp;
        resp=mod(resp+mod(x*temp,M),M);
    }

   
    cout<<resp;

}