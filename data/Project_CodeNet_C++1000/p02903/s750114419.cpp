#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int H,W,A,B;
    cin>>H>>W>>A>>B;
    rep(i,H){
        rep(j,W){
            if(i<B && j<A)cout<<0;
            else if(i>=B && j>=A)cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }
}