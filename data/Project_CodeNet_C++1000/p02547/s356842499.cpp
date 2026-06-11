#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int n;cin >> n;
  int d[n][2];
  rep(i,n){
    cin >> d[i][0] >> d[i][1];
  }
  for(int i=0;i<n-2;++i){
    if(d[i][0] == d[i][1]){
      if(d[i+1][0] == d[i+1][1]){
        if(d[i+2][0] == d[i+2][1]){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}