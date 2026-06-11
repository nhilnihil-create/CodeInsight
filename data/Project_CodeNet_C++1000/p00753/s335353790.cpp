#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define RFOR(i,m,n) for(int i=m;i>=n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int a[300000];


int main(){
  
  fill(a+2,a+300000,1);

  FOR(i,2,300000){
    if(!a[i]) continue;
    for(int j=2;i*j<300000;j++){
      a[i*j]=0;
    }
  }

  for(int i=1;i<300000;i++){
    a[i]+=a[i-1];
  }

  while(1){
    int n;
    cin>>n;
    if(n==0) break;
    cout<<a[2*n]-a[n]<<endl;
  }

  return 0;
}
