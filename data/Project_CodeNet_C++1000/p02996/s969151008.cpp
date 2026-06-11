#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<pair<int, int>> tasks; //deadLine, cost.
  
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    tasks.push_back({b, a});
  }
  
  sort(tasks.begin(),tasks.end());
  
  long long workingTime=0;
  for (auto t: tasks) {
    
    long long deadLine, cost;
    tie(deadLine, cost) = t;
    
    workingTime += cost;
    if(workingTime>deadLine) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  
  return 0;
  
}