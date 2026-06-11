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
  bool ok=false;
  for(int i=1;i<=9;i++){
    if(N%i==0&&N/i<=9){ok=true;}
  }
  if(ok){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;  
}