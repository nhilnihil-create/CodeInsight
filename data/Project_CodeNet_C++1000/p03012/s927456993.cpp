#include <bits/stdc++.h>
#define Rep(i,n) for(int i=0;i<n;i++)
#define Repr(i,n) for(int i=n;i>=0;i--)
#define For(i,m,n) for(int i=m;i<n;i++)
#define Inf 1LL<<60
#define All(v) v.begin(),v.end()
#define Mod (ll)(1e9+7)
using namespace std;
typedef long long ll;

int main()
{
    ll n,w[100]={0},sum=0;
    cin>>n;
    Rep(i,n){
        cin>>w[i];
        sum+=w[i];
    }
    ll s1=0,s2=sum,tmp=sum;
    Rep(i,n){
        s1+=w[i];
        s2-=w[i];
        if(abs(s2-s1)<tmp){
            tmp=abs(s2-s1);
        }else{
            break;
        }
    }
    cout<<tmp<<endl;
    return 0;
}