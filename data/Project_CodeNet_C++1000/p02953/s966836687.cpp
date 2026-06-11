#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
  int N;
  cin>>N;
  vector<int>H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  int pre=0;
  for(int i=0;i<N;i++){
    if(pre<=H[i]-1){
      pre=H[i]-1;}
    else if(pre<=H[i]){
      pre=H[i];}
    else{cout<<"No"<<endl;return 0;}
    }
    cout<<"Yes"<<endl;
  return 0;}