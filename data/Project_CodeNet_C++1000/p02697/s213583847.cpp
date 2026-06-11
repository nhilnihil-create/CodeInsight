#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> p(n/2);
    if(m%2==0){
        rep(i,m/2){
            p[i].first=i+1;
            p[i].second=m+1-i;
        }
        rep(i,m/2){
            p[i+m/2].first=m+2+i;
            p[i+m/2].second=2*m+1-i;
        }
    }else{
        rep(i,m/2){
            p[i].first=i+1;
            p[i].second=m-i;
        }
        rep(i,(m+1)/2){
            p[i+m/2].first=m+1+i;
            p[i+m/2].second=2*m+1-i;
        }
    }
    rep(i,m){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
}