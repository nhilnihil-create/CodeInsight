#include<iostream>
using namespace std;

int main() {
  int N; cin >> N;
  long cnt = 0;
  for (int a = 1; a < N; a++) {
    cnt += (N-1)/a;
  }
  cout<<cnt<<endl;
}