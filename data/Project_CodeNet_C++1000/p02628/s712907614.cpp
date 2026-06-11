#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  
  priority_queue<int, vector<int>, greater<int>> X;
  for(int i=0;i<N;i++){
    int L;
    cin >> L;
    X.push(L);
  }
  
  int Ans=0;
  for(int i=0;i<K;i++){
    Ans += X.top();
    X.pop();
  }
  
  cout << Ans << endl;

}
