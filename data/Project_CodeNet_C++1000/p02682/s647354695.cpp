#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll a,b,c,k;cin>>a>>b>>c>>k;
    ll sum = a;
    if(sum>=k){
        cout<<k<<endl;
        return 0;
    }
    sum+=b;
    if(sum>=k){
        cout<<a<<endl;
        return 0;
    }
    a-=(k-sum);
    cout<<a<<endl;
    return 0;

}