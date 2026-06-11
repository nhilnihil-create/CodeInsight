#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int M;
  int D;
  cin>>M>>D;
  int count=0;
  for(int i=1;i<=M;i++){
      for(int k=1;k<=D;k++){
        int d1=k%10;
        int d10=k/10;
        if(d1>=2&&d10>=2&&d1*d10==i){count++;}
      }
    }
  cout<<count<<endl;
  return 0;}