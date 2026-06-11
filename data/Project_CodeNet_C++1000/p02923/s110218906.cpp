#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H.at(i);
  }
  int answer = 0;
  for(int i = 0; i < N-1; i++){
    int j, count;
    for(j = i, count = 0; j < N - 1 && H.at(j+1) <= H.at(j); j++, count++){
      i ++;
    }
    if(answer < count) answer = count;
  }
  cout << answer << endl;
}