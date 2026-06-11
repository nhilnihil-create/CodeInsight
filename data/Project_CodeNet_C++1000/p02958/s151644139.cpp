#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++){
    cin >> p.at(i);
  }
  vector<int> vec(0);
  for (int i = 0; i < N; i++){
    vec.push_back(p.at(i));
  }
  sort(vec.begin(), vec.end());
  
  int dif = 0;
  for (int i = 0; i < N; i++){
    if (p.at(i) != vec.at(i)){
      dif++;
    }
  }
  
  if (dif <= 2){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}



