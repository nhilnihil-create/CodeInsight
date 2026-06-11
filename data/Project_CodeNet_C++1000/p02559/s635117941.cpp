#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

struct BIT{
    vector<ll> bit;
    int N;
    //1-indexed
    
    void init(int n_){
        N=n_;
        n_*=2;
        for(int i=30;i>=0;i--){
            if(n_&(1<<i)){
                n_=1<<i;
                n_++;
                break;
            }
        }
        bit.assign(n_,0LL);
    }
    
    ll sum(int i){
        ll s=0;
        while(i>0){
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
    
    //sからtの和=sum(t)-sum(s-1)
    
    void add(int i,ll x){
        while(i<=N){
            bit[i]+=x;
            i+=i&-i;
        }
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    BIT bi;
    bi.init(N);
    
    for(int i=0;i<N;i++){
        ll a;cin>>a;
        bi.add(i+1,a);
    }
    
    while(Q--){
        ll k,a,b;cin>>k>>a>>b;
        if(k){
            cout<<bi.sum(b)-bi.sum(a)<<"\n";
        }else{
            bi.add(a+1,b);
        }
    }
    
}
