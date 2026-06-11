#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  map<int, int> M;
  rep(i, N){
    int a;
    cin >> a;
    M[a]++;
  }

  if(M.size() == 1 && M.find(0) != M.end()){
    cout << "Yes" << endl;
    return 0;
  }

  if(N % 3 != 0){
    cout << "No" << endl;
    return 0;
  }

  if(M.size() == 2){
    for(auto mp : M){
      if(0 == mp.first && N / 3 == mp.second){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  if(M.size() == 3){
    int tmp = 0;
    for(auto mp : M){
      if(N / 3 == mp.second){
        tmp ^= mp.first;
      }
      else{
        cout << "No" << endl;
        return 0;
      }
    }
    if(0 == tmp){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
