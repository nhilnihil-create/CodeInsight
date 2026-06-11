#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    reverse(s.begin(),s.end());
    s+='0';
    int n=s.size();
    vector<vector<ll>> t(2,vector<ll>(n+10,1e9));
    t[0][0]=0;
    rep(i,n){
        int now=s[i]-'0';
        rep(j,2){
            now+=j;
            rep(k,10){
                int nj=0;
                int b=k-now;
                if(b<0){
                    nj=1;
                    b+=10;
                }
                chmin(t[nj][i+1],t[j][i]+k+b);
            }
        }
    }
    ll res=1e9;
    chmin(res,min(t[0][n],t[1][n]));
    cout<<res<<endl;
}