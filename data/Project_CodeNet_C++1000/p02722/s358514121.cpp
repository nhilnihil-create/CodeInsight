#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    ll a=n-1;
    ll res=1;
    for(int i=2;i<=sqrt(a);i++){
        ll cnt=1;
        while(a%i==0){
            cnt++;
            a/=i;
        }
        res*=cnt;
    }
    if(a>=2)res*=2;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i!=0)continue;
        a=n;
        ll b=n,c=n/i;
        while(a%i==0)a/=i;
        while(b%c==0)b/=c;
        if(a%i==1)res++;
        if(b%i==1)res++;
        if(i==c)res--;
    }
    
    cout<<res<<endl;
}