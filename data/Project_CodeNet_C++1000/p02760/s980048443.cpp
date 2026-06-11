#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  vector<vector<int>>A(3,vector<int>(3));
  vector<vector<bool>>use(3,vector<bool>(3,false));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>A[i][j];
    }
  }
  int N;
  cin>>N;
  for(int q=0;q<N;q++){
    int b;
    cin>>b;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(A[i][j]==b){use[i][j]=true;}
      }
    }
  }
  for(int i=0;i<3;i++){
    bool ok=true;
    for(int j=0;j<3;j++){
      if(!use[i][j]){ok=false;}
    }
    if(ok){cout<<"Yes"<<endl;return 0;}
  }
  for(int j=0;j<3;j++){
    bool ok=true;
    for(int i=0;i<3;i++){
      if(!use[i][j]){ok=false;}
    }
    if(ok){cout<<"Yes"<<endl;return 0;}
  }
  if(use[0][0]&&use[1][1]&&use[2][2]){cout<<"Yes"<<endl;return 0;}
  if(use[0][2]&&use[1][1]&&use[2][0]){cout<<"Yes"<<endl;return 0;}
  cout<<"No"<<endl;
  return 0;
}