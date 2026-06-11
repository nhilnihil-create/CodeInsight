#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
  string s;
  cin>>s;
  map<char,int> m;
  rep(i,4){
   m[s[i]]++; 
  }
  bool ans=true;
  for(auto v:m){
    if(v.second!=2) ans=false;
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}