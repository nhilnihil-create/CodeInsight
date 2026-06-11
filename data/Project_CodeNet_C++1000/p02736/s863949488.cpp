#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};
struct edge2{ll from,to,cost;};

int dtwo[1000005],N;

void d_init(){
    dtwo[0]=dtwo[1]=0;
    FOR(i,2,N+1){
        int now_i=i;
        int cnt=0;
        while(now_i%2==0){
            cnt++;
            now_i/=2;
        }
        dtwo[i]=dtwo[i-1]+cnt;
    }
}

int COM_2(int N,int i){
    int k=dtwo[N]-(dtwo[i]+dtwo[N-i]);
    if(k==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    cin >> N;
    d_init();
    string S;
    cin >> S;
    bool b=true;
    rep(i,N){
        S[i]=S[i]-1;
        if(S[i]=='1'){
            b=false;
        }
    }
    ll ans=0;
    if(b){
        rep(i,N){
            if(S[i]=='2'){
                S[i]='1';
            }
        }
    }
    else{
        rep(i,N){
            if(S[i]=='2'){
                S[i]='0';
            }
        }
    }
    rep(i,N){
        if(S[i]=='1'){
            ans+=COM_2(N-1,i);
            ans%=2;
        }
    }
    if(b){
        ans*=2;
    }
    cout << ans << endl;
}
