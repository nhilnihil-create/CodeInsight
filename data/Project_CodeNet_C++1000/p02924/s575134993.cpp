#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  signed long long answer = 0;
  for(int i = 1; i < N; i++){
    answer += i;
  }
  cout << answer << endl;
}
