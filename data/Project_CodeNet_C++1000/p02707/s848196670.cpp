#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  
  vector<int> a(N);
  for (int i=0; i<N-1;i++){
    int b;
    cin >> b;
    a.at(b-1)++;
  }
  for (int i=0; i<N; i++){
    cout << a.at(i) << endl;
  }
}