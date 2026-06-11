#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

string f(int x){
  string t;
  for(int i=0;i<3;i++){
    t+=x%10+'0';
    x/=10;
  }
  reverse(t.begin(),t.end());
  return t;
}
int main() {
  int N;
  cin>>N;
  string s;
  cin>>s;
  int ans=0;
  for(int i=0;i<=999;i++){
    string t=f(i);
    int v=0;
    for(int j=0;j<N;j++){
      if(s[j]==t[v]){v++;}
    }
    if(v==3){ans++;}
  }
  cout<<ans<<endl;
  return 0;  
}