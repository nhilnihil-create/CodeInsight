#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int N, M;
  cin >> N >> M;
  int a = 0;
  int b = 0;
  for (int i = 0; i < N + M; i++)
  {
    a += i;
  }
  b += N * M;
  a -= b;
  cout << a << endl;
}