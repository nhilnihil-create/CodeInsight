#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  rep(i,n) cin>>h[i];
  int mx=h[0];
  for(int i=1;i<n;i++){
    mx=max(mx,h[i]);
    if(h[i]<=mx-2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}