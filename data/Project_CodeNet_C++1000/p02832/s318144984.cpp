#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  
  vector<int> A(N);
  int T = 0;//砕くべきレンガの数
  int C = 1;//Aがこの数字ならレンガを残す
  
  for(int i = 0; i < N; i++){cin >> A.at(i);}
  for(int i = 0; i < N; i++)
  {
    if(A.at(i) == C){C++;}
    else{T++;}
  }
  if(T == N){cout << "-1" << endl;}
  else{cout << T << endl;}
}