#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int H,W,A,B;
  cin>>H>>W>>A>>B;
  vector<vector<int>>s(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
       if(i<B&&j<A){s[i][j]=0;}
       else if(i<B&&j>=A){s[i][j]=1;}
       else if(i>=B&&j<A){s[i][j]=1;}
       else{s[i][j]=0;}
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
        cout<<s[i][j];
    }cout<<endl;
  }
  return 0;  
}