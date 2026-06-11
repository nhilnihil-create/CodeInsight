#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<deque>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<bitset>
#include<time.h>
#include<cstdlib>
#include<cassert>
#define ll long long
using namespace std;
                   
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin); 
    freopen("out","w",stdout);
#endif
  int n;
  while(cin>>n,n){
    map<char,char> mp;
    for(int i=0;i<n;i++){
      char b,c;cin>>b>>c;
      mp[b]=c;
    }
    string ans="";
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
      char a;cin>>a;
      auto ite=mp.find(a);
      if(ite!=mp.end()){
        ans+=mp[a];
      }else{
        ans+=a;
      }
    }
    cout<<ans<<"\n";
  }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}