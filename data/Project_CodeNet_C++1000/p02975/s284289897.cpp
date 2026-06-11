#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
  int N, input;
  cin >> N;
  if(N % 3 == 0){
    map<int, int> m;
    int count = 0, x, y, z;
    x = y = z = -1;
    rep(i, N){
      cin >> input;
      if(m.count(input) == 0){
        if(count < 3){
          if(x == -1) x = input;
          else if(y == -1) y = input;
          else z = input;
          m[input]++;
          count++;
        }else{
          cout << "No" << endl;
          return 0;
        }
      }else{
        m[input]++;
      }
    }
    if(y == -1){
      if(x == 0) cout << "Yes" << endl;
      else cout << "No" << endl;
    }else if(z == -1){
      if(x == 0 || y == 0){
        if(y == 0) swap(x, y);
        if(2*m[x] == m[y]) cout << "Yes" << endl;
        else cout << "No" << endl;
      }else cout << "No" << endl;
    }else{
      if(((x ^ y ^ z) == 0) && m[x] == m[y] && m[y] == m[z]) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }else{
    rep(i, N){
      cin >> input;
      if(input != 0){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
  return 0;
}