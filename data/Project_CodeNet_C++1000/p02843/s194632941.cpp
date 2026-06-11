#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int x;
  cin >> x;
  vector<int> buc(100001,0);
  queue<int> q;
  q.push(0);
  buc[0] = 1;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    vector<int> d = {100,101,102,103,104,105};
    rep(i,6){
      int next = now + d[i];
      if(next < 0) continue;
      if(next > 100000) continue;
      if(buc[next] == 0){
        buc[next] = 1;
        q.push(next);
      }
    }
  }
  cout << buc[x] << endl;
}