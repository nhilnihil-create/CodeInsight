#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(v) v.bigin(),v.end()
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define R(a) a=sqrt(a)
#define POW(a,b) a=pow(a,b)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    FAST;
    ll x,t;
    ll k=0;
    ll d=360;
    cin>>x;
    while(true){
        if(d%x==0){
            k=d/x;
            break;
        }
        else{
            d+=360;
        }
    }
    cout<<k;
    
}
