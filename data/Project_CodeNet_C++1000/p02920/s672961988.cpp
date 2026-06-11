#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int N;
int big = 0;
multiset<int> S;

int main(){
  cin >> N;
  for(int i=0; i < (1 << N); i++){
    int elm;
    cin >> elm;
    S.insert(elm);
    big = max(big, elm);
  }

  vector<int> T;
  T.push_back(big);
  S.erase(S.find(big));

  for(int i=0; i<N; i++){
    vector<int> uT;
    for(int elm : T){
      auto itr = S.lower_bound(elm);
      if(itr == S.begin()){
        cout << "No" << endl;
        return 0;
      }
      --itr;
      uT.push_back(*itr);
      S.erase(itr);
    }

    for(int elm: uT){
      T.push_back(elm);
    }
  }
  cout << "Yes" << endl;
  return 0;
}
