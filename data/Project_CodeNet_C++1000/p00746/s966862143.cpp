#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,x,n) for(int i=(x);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
const int MOD=1e9+7;
const int INF=1e15;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
template<typename T> void cmax(T &a, T b) {a = max(a, b);}
template<typename T> void cmin(T &a, T b) {a = min(a, b);}
signed main(){
  int n;
  while(cin>>n,n){
    vector<int> x(500,0),y(500,0);
    x[0]=y[0]=0;
    int xmax=0,xmin=0,ymax=0,ymin=0;
    rep(i,n-1){
      int a,d;
      cin>>a>>d;
      x[i+1]=x[a]+dx[d];
      y[i+1]=y[a]+dy[d];
      cmin(xmin,x[i+1]);
      cmin(ymin,y[i+1]);
      cmax(xmax,x[i+1]);
      cmax(ymax,y[i+1]);
    }
    cout<<xmax-xmin+1<<' '<<ymax-ymin+1<<endl;
  }


 return 0;
}

