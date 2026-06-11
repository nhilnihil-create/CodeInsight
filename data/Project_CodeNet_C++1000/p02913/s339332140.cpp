#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
const vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T>void debag(const vector<T> &a){cerr<<"debag :";for(auto v:a)cerr<<v<<" ";cerr<<"\n";}
template<class T>void print(const vector<T> &a){for(auto v:a)cout<<v<<" ";cout<<"\n";}
template<class T> struct RollingHash{
    using ull=unsigned long long int;
    const ull M=(1ull<<61)-1;
    const ull mask30 = (1ull << 30) - 1;
    const ull mask31 = (1ull << 31) - 1;
    const ull mask61 =M;
    vector<ull> hash,pows;
    ull base;

        // mod 2^61-1
    ull cal_mod(ull x){
        ull xu=(x>>61);
        ull xd=(x&mask61);
        ull res=xu+xd;
        if(res>=M)res-=M;
        return res;
    }

    //a*b mod 2^61-1
    ull mul(ull a,ull b){
        ull au=(a>>31),bu=(b>>31);
        ull ad=(a&mask31),bd=(b&mask31);
        ull mid=ad*bu+au*bd;
        ull midu=(mid>>30);
        ull midd=(mid&mask30);
        return cal_mod(au*bu*2+midu+(midd<<31)+ad*bd);
    }


    RollingHash(const T &a,ull base):hash(a.size()+1,0),pows(a.size()+1,1){
		for(int i = 0; i <int (a.size()); i++) {
            pows[i + 1] =mul(pows[i], base);
            hash[i + 1] =cal_mod(mul(hash[i], base) + ull(a[i]));
            if(hash[i+1]>=M)hash[i+1]-=M;
		}
    }
    //[b1,b1+len]と[b2,b2+len]が一致するかどうか
    bool match(int b1, int b2,int len){
        ull h1 = cal_mod(hash[b1+len]+M-mul(hash[b1], pows[len]));
        ull h2 = cal_mod(hash[b2 + len]+M-mul(hash[b2],pows[len]));
        return (h1 == h2);
    }
    //[l,l+len]のハッシュ値
    ull get(int l, int len){
        return cal_mod(hash[l+len] + M - mul(hash[l], pows[len]));
    }
};
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    RollingHash<string> rh(s,1007);
    int l=0,r=n/2+1,mid;
    while(r-l>1){
        int mid=(l+r)/2;
        map<unsigned long long,int> mp;
        bool ok=false;
        for(int i=0;i<n-mid+1;i++){
            unsigned long long val=rh.get(i,mid);
            if(mp.count(val)){
                if(i-mp[val]>=mid)ok=true;
            }else{
              mp[rh.get(i,mid)]=i;
            }
        }
        if(ok)l=mid;
        else r=mid;
    }
    cout<<l<<"\n";
}