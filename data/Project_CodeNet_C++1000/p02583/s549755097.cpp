#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int64_t> l(n);
  for (int i = 0; i < n; i++){
    cin >> l.at(i);
  }
  int count = 0;
  for (int i = 0; i < n - 2; i++){
    for (int j = i + 1; j < n - 1; j++){
      for (int k = j + 1; k < n; k++){
        if (l.at(i) != l.at(j) && l.at(j) != l.at(k) && l.at(k) != l.at(i)){
          if (max(l.at(i), max(l.at(j), l.at(k))) * 2 < l.at(i) + l.at(j) + l.at(k)){
            count++;
          }
        }
      }
    }
  }
  cout << count << endl;
}