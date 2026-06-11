#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
int main(){
  int n,m;
  string s;
  cin >> n >> m >> s;
  int now = 0;
  now = n;
  vector<int> res;
  bool possible = true;
  while(now > 0){
    bool can = false;
    for(int i = max(now - m,0);i < now;i++){
      if(s[i] == '0'){
        //cout << i << endl;
        can = true;
        res.insert(res.begin(),now - i);
        now = i;
        break;
      }
    }
    if(!can){
      possible = false;
      break;
    }
  }
  if(possible){
    for(int i = 0;i < res.size();i++)cout << res[i] << " ";
    cout << endl;
  }
  else{
    cout << -1 << endl;
  }
}