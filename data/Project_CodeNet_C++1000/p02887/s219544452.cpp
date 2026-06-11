#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=10007;

int main() {
  int N;
  cin>>N;
  string S;
  cin>>S;
  int sum=1;
  for(int i=0;i<N-1;i++){
    if(S[i]!=S[i+1]){sum++;}
  }
  cout<<sum<<endl;
  return 0;  
}