#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, L;
  cin >> N >> L;
  vector<int> taste(0);
  for (int i = 0; i < N; i++){
    taste.push_back(L + i);
  }
  int sum = 0;
  for (int i = 0; i < N; i++){
    sum += taste[i];
  }
  
  for (int i = 0; i < N; i++){
    if (taste[i] == 0){
      cout << sum << endl;
      return 0;
    }
  }
  
  if (L >= 0){
    cout << sum - L << endl;
  }
  else{
    if (sum - L - sum > sum - taste[N - 1] - sum){
      cout << sum - taste[N - 1] << endl;
    }
    else{
      cout << sum - L << endl;
    }
  }
}
