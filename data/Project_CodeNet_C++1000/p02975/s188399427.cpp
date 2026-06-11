#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  map<long, long> mp;
  long a;
  for(int i = 0; i < N; i++){
    cin >> a;
    mp[a]++;
  }
  int flag = 1, sub = 0;
  if(N % 3 == 0){
    if(mp.size() == 3){
      for(auto i = mp.begin(); i != mp.end(); ++i){
        sub ^= i->first;
        if(i->second != N /3)flag = 0;
      }
      cout << (flag == 1 && sub == 0?"Yes":"No") << endl;
    } else if(mp.size() == 2 && mp[0] == N / 3)cout << "Yes" << endl;
    else if(mp[0] == N)cout << "Yes" << endl;
    else cout << "No" << endl;
  } else if(mp[0] == N)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}