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
  map<int,string> mp;
  vector<int> pena(n);
  int ans=0;
  int pans=0;
  rep(i,m){
    int p;
    string s;
    cin>>p>>s;
    if(mp[p]=="AC") continue;
    if(s=="AC"){
      mp[p]="AC";
      ans++;
    }
    if(s=="WA"){
      pena[p-1]++;
    }
  }
  rep(i,n){
    if(mp[i+1]=="AC"){
      pans+=pena[i];
    }
  }
  cout<<ans<<" "<<pans<<endl;
}
