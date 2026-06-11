#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n;
  vector<queue<int>> an(n);
  for(int i=0; i<n; ++i) for(int j=0; j<n-1; ++j){
    cin >> x;
    --x;
    an[i].push(x);
  }
  queue<int> que1;
  for(int i=0; i<n; ++i) que1.push(i);
  int day = 0;
  int mach = n *(n-1) /2;
  while(mach >0){
    ++day;
    vector<bool> played(n,false);
    queue<int> que2;
    while(!que1.empty()){
      x = que1.front();
      que1.pop();
      if(played[x] || an[x].empty()) continue;
      int y = an[x].front();
      if(an[y].front() == x){
        played[x] = true;
        played[y] = true;
        que2.push(x);
        que2.push(y);
        --mach;
      }
    }
    for(int i=0; i<n; ++i) if(played[i]) an[i].pop();
    /*
    cout << "day" << day << " ";
    for(int i=0; i<n; ++i){
      cout << i << ":";
      if(played[i]) cout << "play ";
      else cout << "stay ";
    }
    cout << endl;
    */
    if(que2.empty()){
      cout << -1 << endl;
      return 0;
    }
    que1 = que2;
    while(!que2.empty()) que2.pop();
  }
  cout << day << endl;
}