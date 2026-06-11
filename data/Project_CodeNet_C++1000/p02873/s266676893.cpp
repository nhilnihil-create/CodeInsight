#include <bits/stdc++.h>
using namespace std;

#define IOS std::cin.tie(0);std::ios_base::sync_with_stdio(false)

#define ll      long long
#define Fi      first
#define Se      second
#define Pb      push_back
#define vi      vector<int>
#define vp      vector<pair<int,int>>
#define vvi     vector<vector<int>>
#define vvp     vector<vector<pair<int,int>>>
using Graph  =  vector<vector<int>>;

#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define output_s(s) printf("%s\n",(s).c_str())
#define END cout<<"\n"

#define rep(i,n)        for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m)      for(int i=(int)(n);i<(int)(m);i++)
#define RepS(i,n,m)     for(int i=(int)(n);i<=(int)(m);i++)
#define RRepS(i,n,m)    for(int i=(int)(n);i>=(int)(m);i--)
#define SRepS(i,n,m)    for(int i=(int)(n);i*i<=(int)(m);i++)
#define RepA(x)         for(auto &item:(x))

void CINT(){} //@shibh308's template
template<class Head,class... Tail> void CINT(Head&& head,Tail&&... tail){cin>>head; CINT(move(tail)...);}    
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
#define VCIN(x) for(auto &item:x) cin>>item

void OUT(){}
template<class Head,class...Tail> void OUT(Head&& head,Tail&&...tail){cout<<head<<(sizeof...(tail)?" ":"\n"); OUT(move(tail)...);}
#define COUT(...) OUT(__VA_ARGS__)

template<typename TypeInt>TypeInt GCD(TypeInt a,TypeInt b){return a%b==0?b:GCD(b,a%b);} //最大公約数
template<typename TypeInt>TypeInt LCM(TypeInt a,TypeInt b){return a*b/GCD(a,b);} //最小公倍数
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
template<class T>bool comp(T a,T b){return abs(a)<abs(b);} //比較関数

void YES(bool f){printf(f?"YES\n":"NO\n");}
void Yes(bool f){printf(f?"Yes\n":"No\n");}
void Possible(bool f){printf(f?"Possible\n":"Impossible\n");}
void POSSIBLE(bool f){printf(f?"POSSIBLE\n":"IMPOSSIBLE\n");}

//---------------------Template------------------------//

//Prime Factorization
//The result is stored in the array
void PrimeFactorize(long long num,vector<long long> &ret){
    vector<long long> prime(num+1,0);
    vector<long long>::iterator it;
    while(num%2==0){
        num /= 2;
        prime[2]++;
    }
    for(int i=3;i<=num;i++){
        while(num%i==0){
            num /= i;
            prime[i]++;
        }
    }
    copy(prime.begin(),prime.end(),back_inserter(ret));
}

//Judge the prime number
bool IsPrime(int x){
    if(x<2) return false;
    else if(x==2) return true;
    else if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0)return false;
    }
    return true;
}

//----------------------Library------------------------//

//const int dx[4]={1,0,-1,0};
//const int dy[4]={0,1,0,-1};
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int NMAX = 55;
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-10;
const int MOD = 1e9+7;
bool flag = false;

//----------------------Global-------------------------//

signed main(){
    SCIN(s);
    int n=s.size();
    vi a(n+1,0);
    rep(i,n){
        if(s[i]=='<')chmax(a[i+1],a[i]+1);
    }
    RRepS(i,n-1,0){
        if(s[i]=='>')chmax(a[i],a[i+1]+1);
    }
    ll ans=0;
    rep(i,n+1)ans+=a[i];
    COUT(ans);

    return 0;
}