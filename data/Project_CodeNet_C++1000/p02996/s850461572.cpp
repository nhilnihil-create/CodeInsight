#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  pair<int, int> tasks[n];
  for(int i=0; i<n; i++) {
    int a,b;
    cin>>a>>b;
    pair<int, int> task;
    task.first = b;
    task.second = a;
    tasks[i] = task;
  }

  sort(tasks, tasks + n);

  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += tasks[i].second;
    if(sum>tasks[i].first) {
      cout<<"No"<<endl;
      return 0;
    }
  }

  cout<<"Yes"<<endl;

  return 0;
}