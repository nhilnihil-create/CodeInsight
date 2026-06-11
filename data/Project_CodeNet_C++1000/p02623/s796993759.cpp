#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N,M,K;
    cin >>N>>M>>K;
    vector<ll> A(N);
    vector<ll> B(M);
    vector<ll> sumA(N+1);
    vector<ll> sumB(M+1);
    
    rep(i,N){
        cin>>A[i];
        sumA[i+1]=sumA[i]+A[i];
    }
    rep(i,M){
        cin>>B[i];
        sumB[i+1]=sumB[i]+B[i];
    }
    ll l=0;
    ll r=N+M;
    ll now;
    map<ll,ll>seen;
    while(1){
        now = (l+r)/2;
        ll m = INF;
        rep(i,now+1){
            if(i<=N && now-i<=M)
                chmin(m,sumA[i]+sumB[now-i]);
        }
        //cout<<m<<endl;
        if(m<=K){
            if(seen[now]){
                cout<<now<<endl;
                return 0;
            }
            l = now+1;
        }else{
            r = now-1;
        }
        seen[now]=1;
        //cout<<now<<endl;

    }

    return 0;
    

}