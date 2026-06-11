#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int>H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  int MAX=0,cnt=0;
  for(int i=0;i<N;i++){
    if(i==N-1){chmax(MAX,cnt);}
    else if(H[i]>=H[i+1]){cnt++;}
    else {chmax(MAX,cnt);cnt=0;}
    //cout<<cnt<<endl;
  }
  cout<<MAX<<endl;
  return 0;  
}