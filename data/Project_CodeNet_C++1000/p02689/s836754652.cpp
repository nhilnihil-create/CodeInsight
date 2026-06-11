#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> h(N);
  for(int i = 0; i < N; i++){
    cin >> h.at(i);
  }
  
  vector<bool> A(N, true);
  
  int a, b;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    if(h.at(a - 1) > h.at(b - 1)) swap(a, b);
    A.at(a - 1) = false;
    if(h.at(a - 1) == h.at(b - 1)) A.at(b - 1) = false;
  }
  
  int count = 0;
  
  for(int i = 0; i < N; i++){
    if(A.at(i)) count++;
  }
  
  cout << count << endl;
  
}