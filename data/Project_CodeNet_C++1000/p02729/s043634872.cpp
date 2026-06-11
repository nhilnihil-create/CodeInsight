#include <iostream>
using namespace std;

int N;
int M;

int main(){
  cin >> N >> M;
  cout << (N * (N - 1) / 2) + (M * (M - 1) / 2);
}