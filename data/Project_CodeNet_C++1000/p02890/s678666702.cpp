#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  map<int,int> mp;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    mp[x]++;
  }
  priority_queue<int> PQ;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    PQ.push(itr->second*-1);
  }
  
  vector<int> ans(N);
  int s = PQ.size();
  for(int i=s-1; i>0; i--){
    int x = PQ.top();
    ans[i] = x*-1;
    PQ.pop();
    while(x != 0){
      int y = PQ.top();
      PQ.pop();
      y--;
      PQ.push(y);
      x++;
    }
  }
  
  ans[0] = N;
  
  for(int i=0; i<N; i++){
    cout << ans[i] << endl;
  }
}