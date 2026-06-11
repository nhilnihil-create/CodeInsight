#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
#define PB push_back

main(){
  int n;
  cin>>n;
  while(n--){
    string str;
    cin>>str;
    set<string> ans;

    for(int i=1;i<str.size();i++){
      string l,r;
      l=str.substr(0,i);
      r=str.substr(i,str.size()-i);
      ans.insert(l+r);
      ans.insert(r+l);
      reverse(l.begin(),l.end());
      ans.insert(l+r);
      ans.insert(r+l);
      reverse(l.begin(),l.end());
      reverse(r.begin(),r.end());
      ans.insert(l+r);
      ans.insert(r+l);
      reverse(l.begin(),l.end());
      ans.insert(l+r);
      ans.insert(r+l);
    }
    cout<<ans.size()<<endl;
  }
}