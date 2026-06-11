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
    ll N,A,B;
    cin>>N>>A>>B;
    if((A-B)%2==0){
        cout<<abs(A-B)/2<<endl;
        return 0;
    }
    cout<<min((A+B-1)/2,(2*N-A-B+1)/2)<<endl;
}