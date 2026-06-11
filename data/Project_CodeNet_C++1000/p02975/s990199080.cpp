#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

template<class T> ll llpow(T x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}

#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rep2(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    bool che=true;
    unordered_map<int,int> cnt;
    rep(i,n)cnt[a[i]]++;
    if(cnt.size()>3)che=false;
    else if(cnt.size()==3){
        if(n%3)che=false;
        int v[cnt.size()];
        int k[cnt.size()];
        int i=0;
        for(auto it=cnt.begin();it!=cnt.end();it++){
            v[i]=it->second;
            k[i]=it->first;
            i++;
        }
        if((v[0]!=v[1]||v[1]!=v[2])){
           che=false;
        }
        int tmp=0;
        rep(i,cnt.size())tmp^=k[i];
        if(tmp!=0)che=false;
    }
    else if(cnt.size()==2){
        if(n%3)che=false;
        int v[2];
        int i=0;
        bool zero=false;
        for(auto it=cnt.begin();it!=cnt.end();it++){
            if(it->first==0)zero=true;
            v[i++]=it->second;
        }
        if(!zero){che=false;}
        if(che&&!((2*v[1]==v[0])||(2*v[0]==v[1]))){che=false;}
    }
    else if(cnt.size()==1){
        if(cnt.begin()->first!=0)che=false;
    }

    if(che)cout<<"Yes"<<endl;
    else {
        cout<<"No"<<endl;
    }
    return 0;
}


