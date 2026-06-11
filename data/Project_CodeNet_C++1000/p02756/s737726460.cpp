#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int Q;
  cin >> S >> Q;
  
  vector<tuple<int,int,char>> V(Q);
  
  for (int i = 0; i < Q; i++) {
    cin >> get<0>(V.at(i));
    
    if (get<0>(V.at(i)) == 1) {
      get<1>(V.at(i)) = 0;
      get<2>(V.at(i)) = 'a';
    }
    
    else
      cin >> get<1>(V.at(i)) >> get<2>(V.at(i));
  }
  int count = 0;
  string first,last;
  for (int j = 0; j < Q; j++) {
    if (get<0>(V.at(j)) == 1) 
      count++;
    
    else {
      if ((get<1>(V.at(j)) == 1 && count%2 == 0) || (get<1>(V.at(j)) == 2 && count%2 == 1))
        first = get<2>(V.at(j)) + first;
      else
        last = last + get<2>(V.at(j));
    }
  }
  S = first + S + last;
  if (count%2 == 0)
    cout << S << endl;
  else {
    reverse(S.begin(),S.end());
    cout << S << endl;
  }
    
      
}
