#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  double N;
  cin >> N;
  
  priority_queue<double> V;
  for (int i = 0; i < N; i++){
    int v;
    cin >> v;
    v *= -1;
    V.push(v);
  }
  
  for (int i = 0; i < N - 1; i++){
    double guzai1, guzai2;
    guzai1 = V.top();
    V.pop();
    guzai2 = V.top();
    V.pop();
    
    V.push((guzai1 + guzai2) / 2);
  }
  
  double ans = V.top() * -1;
  cout << ans << endl;
}