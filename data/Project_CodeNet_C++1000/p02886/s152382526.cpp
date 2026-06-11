#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> d(N);
  for(int i = 0; i < N; i++){
    cin >> d.at(i);
  }
  int result = 0;
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      result = result + d.at(i)*d.at(j);
    }
  }
  cout << result << endl;
}