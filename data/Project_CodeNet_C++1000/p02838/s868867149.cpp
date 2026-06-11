#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<char>>;
using P =pair<int,int>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const ll mod=1000000007;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    ll ans=0;
    rep(i,60){
        int x=0;
        rep(j,n){
            if((a[j]>>i)&1)++x;
        }
        ll sum=x*(n-x)%mod;
        rep(j,i){
            sum=sum*2%mod;
        }
        ans+=sum%mod;
    }
    cout<<ans%mod<<endl;
}