#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int result = 0;
  result += M * (M - 1) / 2;
  result += N * (N - 1) / 2;
  cout << result << endl;
}
