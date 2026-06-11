#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int n; cin>>n;
  vector<vector<pair<int,int>>> eviArr(n);
  for(int i=0; i<n; i++) {
    int eviNum; cin>>eviNum;
    for(int j=0; j<eviNum; j++) {
      int person,isHonest; cin>>person>>isHonest;
      eviArr[i].push_back({person-1,isHonest});
    }
  }
  int ans=0;
  // bit全探索
  for(int i=0; i<pow(2,n); i++) {
    bitset<15> bs(i);
    bool isFinished = true;
    for(int j=0; j<n; j++) {
      if(bs[j]) {
        for(int k=0; k<(int)eviArr[j].size(); k++) {
          if(bs[eviArr[j][k].first]!=eviArr[j][k].second) isFinished=false;
          if(!isFinished) break;
        }
        if(!isFinished) break;
      }
    }
    if(!isFinished) continue;
    ans = max(ans,(int)bs.count());
  }
  cout << ans << endl;
}
