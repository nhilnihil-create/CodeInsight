#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> p;
    if(m%2==0){
        ll buf=m/2;
        rep(i,buf){
            p.push_back({i+1,m-i});
        }
        rep(i,buf){
            p.push_back({m+i+1,2*m+1-i});
        }
    }else{
        ll buf=(m+1)/2;
        rep(i,buf-1){
            p.push_back({i+1,m-i});
        }
        rep(i,buf){
            p.push_back({m+i+1,2*m+1-i});
        }
    }
    rep(i,p.size()){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
}