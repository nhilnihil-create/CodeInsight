#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
void o(ll a,ll b){
    cout<<a<<" "<<b<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    rep(i,0,30){
        ll u=Pow(2,i);
        if(u==n){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    ll las=4;
    for(int i=3;i<=n;i+=4){
        if(i>=7)o(i-3,i-2);
        o(i-2,i);
        o(i,i-1);
        if(i>=7){
            o(i-1,i-3+n);
            o(i-3+n,i-2+n);
        }
        else o(i-1,i-2+n);
        o(i-2+n,i+n);
        o(i+n,i-1+n);
        if(n%4==1||n%4==2)o(1,i+1);
        if(n%4==3&&i<n)o(i-2,i+1);
        if(n%4==0){
            if(i+1==n)break;
            if(i==3)o(i-2,i+1);
            else{
                ll t=1;
                for(;;){
                    t*=2;
                    if(t>i+1){
                        o(i-2,i+1);
                        break;
                    }
                    if(i+1==t){
                        if((n&t)==t){
                            o(t,las);
                            las=t;
                        }
                        else{
                            o(i-2,i+1);
                            
                        }
                        break;
                    }
                }
            }
        }
    }
    if(n%4==1){
        o(n,n-1);
        o(1+n,n+n);
        o(n+n,n-1+n);
    }
    if(n%4==2){
        o(n-1,n-2);
        
        o(1+n,n+n-1);
        o(n+n-1,n-2+n);
        o(n,n-2);
        o(3,n+n);
    }
    if(n%4==0){
        ll u=1;
        ll uu=1;
        for(;;){
            u*=2;
            if(u>n){
                u/=2;
                break;
            }
        }
        for(;;){
            uu*=2;
            if((n&uu)==uu){
                break;
            }
        }
        o(n,u);
        o(n+n,uu);
    }
}
