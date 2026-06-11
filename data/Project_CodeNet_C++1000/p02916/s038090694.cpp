#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n;cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);

    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }
    rep(i,n-1){
        cin>>c[i];
    }
    int ans=0;
    int stock=0;
    rep(i,n){
        if(a[i]==stock+1){
            ans+=c[a[i]-2];
        }
        ans+=b[a[i]-1];

        stock=a[i];

    }

    cout<<ans<<endl;

}