#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,A;
  cin >> N;
  map<int,int> mp;
  for(int i=0;i<N;i++){
    cin >> A;
    mp[A] ++;
  }

  bool all_1 = true;
  for(auto itr=mp.begin();itr!=mp.end();itr++){
    if(itr->second != 1) all_1 = false;
  }
  if(all_1) cout << "YES" << endl;
  else cout << "NO" << endl;
}