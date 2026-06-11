#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<ll,ll> pint;
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ll n,k;cin>>n>>k;
    ll cnt = ((n-2)*(n-1))/2;
    if(cnt<k){
    cout<<"-1"<<endl;
    }
    else{
        k = cnt-k;
        cout<<k+n-1<<endl;
        REP(i,2,n+1){
        cout<<1<<" "<<i<<endl;
        }
        if(k!=0){
        for(int i=2;i<=n;i++){
          REP(j,i+1,n+1){
            cout<<i<<" "<<j<<endl;
            k--;
            if(k==0){
              break;
            }
          }
          if(k==0){
            break;
          }
        }
    }
    }
}