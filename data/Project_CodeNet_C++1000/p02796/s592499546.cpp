#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
  int n,ans=0,t=-10000000;
  cin>>n;
  vector<P> p(n);
  rep(i,n){
    int a,b;
    cin >> a>>b;
    p[i]=P(a+b,a-b);
  }
  sort(p.begin(),p.end());
  rep(i,n){
    if(t<=p[i].second){
      t=p[i].first;
      ans++;
    }
  }
  cout <<ans<<endl;
}