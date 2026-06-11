#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
const int MAX = 100005;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
  int n; cin >> n;
  int c = 1<<n;
  vector<int> s(c);
  rep(i,c) cin >> s[i];
  sort(s.begin(),s.end());
  vector<int> t;
  t.push_back(s.back());
  s.back() = -1;
  rep(i,n){
    vector<int> pa = t;
    sort(pa.begin(),pa.end());
    int a = c-1;
    while(pa.size() > 0 && a >= 0){
      if(s[a] == -1){
        a--;
        continue;
      }
      if(s[a] < pa.back()){
        t.push_back(s[a]);
        pa.pop_back();
        s[a] = -1;
      }
      a--;
    } 
    if(pa.size() > 0){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}