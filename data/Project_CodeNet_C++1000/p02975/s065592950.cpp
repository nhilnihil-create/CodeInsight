#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++){
    mp[a[i]]++;
  }
  if (mp.size() == 1){
    if ((*(mp.begin())).first == 0){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (mp.size() == 2){
    if (N % 3 != 0){
      cout << "No" << endl;
    } else {
      bool ok = false;
      for (auto P : mp){
        if (P.second * 3 == N){
          ok = true;
        }
      }
      if (ok){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  } else if (mp.size() == 3){
    if (N % 3 != 0){
      cout << "No" << endl;
    } else {
      int cnt = 0; 
      for (auto P : mp){
        if (P.second * 3 == N){
          cnt++;
        }
      }
      if (cnt != 3){
        cout << "No" << endl;
      } else {
        vector<int> B;
        for (auto P : mp){
          B.push_back(P.first);
        }
        if ((B[0] ^ B[1]) != B[2]){
          cout << "No" << endl;
        } else {
          cout << "Yes" << endl;
        }
      }
    }
  } else {
    cout << "No" << endl;
  }
}