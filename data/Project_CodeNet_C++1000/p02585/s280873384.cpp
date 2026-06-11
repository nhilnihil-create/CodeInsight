#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ll n,k; cin>>n>>k; ll p[n],c[n];
  rep(i,n){
    cin>>p[i]; p[i]--;
  }
  rep(i,n){
    cin>>c[i];
  }
  ll period[n]; vector<ll> v[n];
  ll sum[n]={},ruis[n][n];
  rep(i,n){
    ll tmp=0,q=i,s=0;
    while(1){
      q=p[q];
      v[i].push_back(q);
      tmp++;
      s+=c[q];
      ruis[i][tmp-1]=s;
      if(q==i){
        period[i]=tmp;
        break;
      }
    }
    sum[i]=s;
  }
  ll ma=-INF,anst;
  rep(i,n){
    ll r=(k-1)%period[i]+1,q=(k-r)/period[i],maxi1=0,maxi2=ruis[i][0];
    for(int j=0;j<r;j++){
      maxi1=max(maxi1,ruis[i][j]);
    }
    for(int j=1;j<min(k,period[i]);j++){
      maxi2=max(maxi2,ruis[i][j]);
    }
    q!=0?(sum[i]>0?anst=q*sum[i]+max(maxi1,(ll)0):anst=maxi2):anst=maxi2;
    ma=max(ma,anst);
  }
  cout<<ma;
}