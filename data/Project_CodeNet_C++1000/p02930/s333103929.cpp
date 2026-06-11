#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
const int mod=1e9+7;

int G[500][500];


void solve(int a,int b,int ctr){
  if(a==b)return;
  int n=b-a+1;
  rep(i,a,a+n/2){
    rep(j,a+n/2,b+1){
      G[i][j]=ctr;
      G[j][i]=ctr;
    }
  }
  solve(a,a+n/2-1,ctr+1);
  solve(a+n/2,b,ctr+1);
  return;
}
  
int main(){
  int n;cin>>n;
  solve(0,n-1,1);
  rep(i,n){
    rep(j,i+1,n){
      if(j>i+1)cout<<" ";
      cout<<G[i][j];
    }
    cout<<endl;
  }
}
    
    



