#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll x;cin>>x;
    vector<ll> ans(1005);
    rep(i,1005){
       ans[i]=pow(i,5);

    }
    for(int i=0;i<=1000;i++) {
        for(int j = 0;j<=1000;j++)
        if(ans[i]-ans[j]==x){
            cout<<i<<" "<<j<<endl;
            return 0;
        }
        else if(ans[i]+ans[j]==x){
            cout<<i<<" "<<j*-1<<endl;
            return 0;
        }

    }

}