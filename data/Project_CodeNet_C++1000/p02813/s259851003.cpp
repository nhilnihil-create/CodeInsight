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
  vector<int>P(N);
  for(int i=0;i<N;i++){
    cin>>P[i];
  }
  vector<int>Q(N);
  for(int i=0;i<N;i++){
    cin>>Q[i];
  }
  vector<int>num(N);
  for(int i=0;i<N;i++){
    num[i]=i+1;
  }
  int cnt=0;
  int a=0,b=0;
  do{
    if(num==P){a=cnt;}
    if(num==Q){b=cnt;}
    cnt++;
  }while(next_permutation(num.begin(),num.end()));
  cout<<abs(a-b)<<endl;
  return 0;  
}