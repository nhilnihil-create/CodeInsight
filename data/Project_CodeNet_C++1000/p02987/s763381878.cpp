#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  if(s[0]==s[1]&&s[1]!=s[2]&&s[2]==s[3]){
    cout<<"Yes"<<endl;
  }
  else{cout<<"No"<<endl;}
  return 0;  
}