#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265


void f(int n){
  int x[1000]={},y[1000]={};
  FOR(i,1,n){
    int b,c;
    cin>>b>>c;
    if(c==0){
      x[i]=x[b]-1;
      y[i]=y[b];
    }
    if(c==1){
      x[i]=x[b];
      y[i]=y[b]-1;
    }
    if(c==2){
      x[i]=x[b]+1;
      y[i]=y[b];
    }
    if(c==3){
      x[i]=x[b];
      y[i]=y[b]+1;
    }
  }
  sort(x,x+n);
  sort(y,y+n);
  
  cout<<x[n-1]-x[0]+1<<' ';
  cout<<y[n-1]-y[0]+1<<endl;
}



int main(){
  int n;
  while(1){
    cin>>n;
    if(n==0) break;
    f(n);
  }

}
