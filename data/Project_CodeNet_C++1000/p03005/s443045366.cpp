#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;

int id[1005][1005];
vector<int>to[1000005];
bool visited[1000005];
int dp[1000005];
bool calculated[1000005];

int toid(int i,int j){
  if(i>j){swap(i,j);}
  return id[i][j];
}

int main() {
  int N,K;
  cin>>N>>K;
  if(K==1){cout<<0<<endl;}
  else{cout<<N-(K-1)-1<<endl;}
  return 0;  
}