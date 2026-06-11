#include <bits/stdc++.h>
using namespace std;
int main () {
  long N;
  cin >> N;
  vector<long> pos, neg;
  long a;
  for(int i = 0;i < N; i++){
    cin >> a;
    if(a < 0)neg.push_back(a);
    else pos.push_back(a);
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());
  vector<pair<long, long>> ans;
  long sub;
  if(pos.size() == 0){
    for(int i = 0; i < N - 1; i++){
      ans.push_back(make_pair(neg.at(N - 1), neg.at(i)));
      neg.at(N - 1) -= neg.at(i);
    }
    cout << neg.at(N - 1) << endl;
  } else if(neg.size() == 0){
    sub = pos.at(0);
    for(int i = 1; i < N - 1; i++){
      ans.push_back(make_pair(sub, pos.at(i)));
      sub -= pos.at(i);
    }
    ans.push_back(make_pair(pos.at(N - 1), sub));
    sub = pos.at(N - 1) - sub;
    cout << sub << endl;
  } else {
    for(int i = 0; i < pos.size() - 1; i++){
      ans.push_back(make_pair(neg.at(0), pos.at(i)));
      neg.at(0) -= pos.at(i);
    }
    for(int i = 0; i < neg.size(); i++){
      ans.push_back(make_pair(pos.at(pos.size() - 1), neg.at(i)));
      pos.at(pos.size() - 1) -= neg.at(i);
    }
    cout << pos.at(pos.size() - 1) << endl;
  }
  for(int i = 0; i < ans.size(); i++){
    cout << ans.at(i).first << ' ' << ans.at(i).second << endl;
  }
  return 0;
}