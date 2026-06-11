#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
  int no_of_input;
  int input;
  vector<int> vect1;
  multiset<int> currhas;
  cin >> no_of_input;
  for(int i=0;i<(1<<no_of_input);i++){
    cin >> input;
    vect1.push_back(input);
  }
  multiset<int> set1;
  sort(vect1.begin(),vect1.end());
  currhas.insert(vect1[vect1.size()-1]);
  for(int i=0;i<vect1.size()-1;i++){
    set1.insert(vect1[i]);
  }
  for(int i=0;i<no_of_input;i++){
    vector<int> temp;
    for(auto k:currhas){
      auto j = set1.lower_bound(k);
      if(j==set1.begin()){
        cout << "No";
        return 0;
      }
      j--;
      temp.push_back(*j);
      set1.erase(j);
    }
    for(auto k:temp){
      currhas.insert(k);
    }
  }
  cout << "Yes";
  
}