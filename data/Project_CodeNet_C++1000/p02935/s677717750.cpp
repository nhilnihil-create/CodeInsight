#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  double ans = 0, tmp;
  for (int i = 0; i < N; i++){
    tmp = vec[i];
    if(i == 0){
      tmp /= pow(2, N - 1);
      ans += tmp;
    }
    else{
      tmp /= pow(2, N - i);
      ans += tmp;
    }
  }
  cout << ans;
}