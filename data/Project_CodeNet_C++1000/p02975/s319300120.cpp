#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<int>a(N);
  int count0 = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    if (a.at(i) == 0){
      count0++;
    }
  }
  if (count0 == N){
    cout << "Yes" << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  
  int diff = 1;
  
  for (int i = 1; i < N; i++) {
    if (a.at(i) != a.at(i-1)){
      diff++;
    }
  }
  
  if (diff > 3){
    cout << "No" << endl;
    return 0;
  }
  
  vector<int>count(3,0);
  count.at(0) = 1;
  vector<int>A(3);
  A.at(0) = a.at(0);
  int j = 1;
  if (diff == 3){
    for (int i = 1; i < N; i++) {
      if (a.at(i) != a.at(i-1)){
        A.at(j) = a.at(i);
        j++;
      }
      count.at(j-1)++;
    }
    if (count.at(1) != count.at(2) || count.at(0) != count.at(1)){
      cout << "No" << endl;
      return 0;
    }
    
    bitset<30>X(A.at(0));
    bitset<30>Y(A.at(1));
    bitset<30>Z(A.at(2));
    bitset<30>B = (X^Y)^Z;
    int C = B.to_ullong();
    if (C == 0){
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    return 0;
  }
  
  if (diff == 2 && count0 * 3 == N){
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;
}
    

