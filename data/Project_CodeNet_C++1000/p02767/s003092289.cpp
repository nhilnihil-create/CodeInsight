#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, temp, ans;
  cin >> N;
  vector<int> data(N);
  for (int i = 0; i < N; i++){
    cin >> data.at(i);
  }
  for (int i = 1; i < 101; i++){
  temp = 0;
    for (int j = 0; j < N; j++){
    temp += (data.at(j) - i) * (data.at(j) - i);
    }
    if (i == 1) ans = temp;
    else{
      if (ans > temp){
        ans = temp;
      }
    }
  }
  cout << ans;
}