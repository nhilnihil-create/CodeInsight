#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin>>N;
  string c;
  cin>>c;
  int RED=0;
  for(int i=0;i<N;i++){
    if(c[i]=='R'){RED++;}
  }
  int out=0;
  for(int i=RED;i<N;i++){
    if(c[i]=='R'){out++;}
  }
  cout<<out<<endl;
  return 0;  
}