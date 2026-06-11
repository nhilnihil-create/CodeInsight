#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    sp(10);
    long double n,k;cin>>n>>k;
    vector<long double> p(n);
    rep(i,n){
        cin>>p[i];
        p[i]=(p[i]+1)/2;
    }
    long double res=0;
    long double tmp=0;
    rep(i,k-1)tmp+=p[i];
    rep(i,n){
        if(i<k-1)continue;
        tmp+=p[i];
        chmax(res,tmp);
        tmp-=p[i-k+1];
    }
    cout<<res<<endl;
}