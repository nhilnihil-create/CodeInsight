#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;
int main() {
  int N;
  cin>>N;
  string s;
  cin>>s;
  if(N%2==0&&s.substr(0,N/2)==s.substr(N/2,N/2)){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;
}
