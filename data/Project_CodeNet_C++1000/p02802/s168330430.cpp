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
  int n,m;
  cin>>n>>m;
  vector<int> ac(n),pena (n);
  rep(i,m){
    int p;
    string s;
    cin>>p>>s;
    --p;
    if(ac[p]) continue;
    if(s=="AC"){
      ac[p]=1;
    }
    else{
      pena[p]++;
    }
  }
  int sum=0;
  int psum=0;
  for(auto x:ac){
    sum+=x;
  }
  rep(i,n){
    if(ac[i]){
    psum+=pena[i];
    }
  }
  cout<<sum<<" "<<psum<<endl;
}