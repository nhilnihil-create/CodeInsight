#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  vector<int> v(9, -1);
  rep(i, 0, 9) cin >> v[i];
  
  int n;
  cin >> n;
  
  vector<int> vv(n, -1);
  rep(i, 0, n){
    cin >> vv[i];
    rep(j, 0, 9){
      if(vv[i] == v[j]){
        v[j] = -1;
        break;
      }
    }
  }
  int f = 0;
  if(v[4] == -1){
    if(v[2] == -1 && v[6] == -1){
      f++;
    }
    else if(v[0] == -1 && v[8] == -1){
      f++;
    }
    else if(v[1] == -1 && v[7] == -1){
      f++;
    }
    else if(v[3] == -1 && v[5] == -1){
      f++;
    }
    
    if(f > 0){
      cout << "Yes\n";
      return 0;
    }
  }
  
  if(v[0] == -1){
    if(v[2] == -1 && v[1] == -1){
      f++;
    }
    else if(v[3] == -1 && v[6] == -1){
      f++;
    }
    if(f > 0){
      cout << "Yes\n";
      return 0;
    }
  }
  
  if(v[8] == -1){
    if(v[2] == -1 && v[5] == -1){
      f++;
    }
    else if(v[7] == -1 && v[6] == -1){
      f++;
    }
    if(f > 0){
      cout << "Yes\n";
      return 0;
    }
  }
  
  cout << "No\n";
}
  