#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
   int h,w;cin>>h>>w;
   char c[h][w];
   rep(i,h)rep(j,w)cin>>c[i][j];
   vector<vector<ll>> vu(h,vector<ll>(w,0)),vd(h,vector<ll>(w,0)),vr(h,vector<ll>(w,0)),vl(h,vector<ll>(w,0));
   rep(i,h){
       rep(j,w){
           if(c[i][j]=='.'){
               vu[i][j]++;
               vd[i][j]++;
               vr[i][j]++;
               vl[i][j]++;
           }
       }
   }
   rep(i,h){
       rep(j,w-1){
           if(c[i][j+1]=='.')vl[i][j+1]+=vl[i][j];
       }
       for(int j=w-1;j>0;j--){
           if(c[i][j-1]=='.')vr[i][j-1]+=vr[i][j];
       }
   }
   rep(j,w){
       rep(i,h-1){
           if(c[i+1][j]=='.')vd[i+1][j]+=vd[i][j];
       }
       for(int i=h-1;i>0;i--){
           if(c[i-1][j]=='.')vu[i-1][j]+=vu[i][j];
       }
   }
   ll res=0;
   rep(i,h){
       rep(j,w){
           ll buf=vu[i][j]+vd[i][j]+vr[i][j]+vl[i][j];
           if(c[i][j]=='.')buf-=3;
           chmax(res,buf);
       }
   }
   
   cout<<res<<endl;
}