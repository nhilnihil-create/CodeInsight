#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  vector<vector<int>>a(3,vector<int>(3));
  rep(i,3){
    rep(j,3){
      cin >> a[i][j];
    }
  }
  int n;
  cin >> n;
  vector<vector<int>>c(3,vector<int>(3));
  rep(i,n){
    int b;
    cin >>b;
    rep(i,3){
      rep(j,3){
        if(a[i][j]==b){
          c[i][j]++;
        }
      }
    }
  }
  if(c[0][0]!=0&&c[0][1]!=0&&c[0][2]!=0){
    cout << "Yes" << endl;
  }
  else if(c[1][0]!=0&&c[1][1]!=0&&c[1][2]!=0){
    cout << "Yes" << endl;
  }
  else if(c[2][0]!=0&&c[2][1]!=0&&c[2][2]!=0){
    cout << "Yes" << endl;
  }
  else if(c[0][0]!=0&&c[1][0]!=0&&c[2][0]!=0){
    cout << "Yes" << endl;
  }
  else if(c[0][1]!=0&&c[1][1]!=0&&c[2][1]!=0){
    cout << "Yes" << endl;
  }
  else if(c[0][2]!=0&&c[1][2]!=0&&c[2][2]!=0){
    cout << "Yes" << endl;
  }
  else if(c[0][0]!=0&&c[1][1]!=0&&c[2][2]!=0){
    cout << "Yes" << endl;
  }
  else if(c[0][2]!=0&&c[1][1]!=0&&c[2][0]!=0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }  

  return 0;

}


