#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll a,v,b,w,t;cin>>a>>v;
    cin>>b>>w;
    cin>>t;
    ll x=v-w;
    ll dis =abs(a-b);
    if(x*t>=dis){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}