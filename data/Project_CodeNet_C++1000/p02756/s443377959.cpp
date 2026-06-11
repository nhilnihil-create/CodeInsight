#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  string S;
  ll Q, T, F;
  char C;
  bool rev = 0;
  vector<char> head, tale;
  cin >> S >> Q;
  for(ll i = 0; i < Q; i++) {
    cin >> T;
    if(T == 1) rev ^= 1;
    else {
      cin >> F >> C;
      if(F == 1) {
        if(rev) tale.push_back(C);
        else head.push_back(C);
      }
      else {
        if(rev) head.push_back(C);
        else tale.push_back(C);
      }
    }
  }
  if(rev) {
    for(ll i = 0; i < tale.size(); i++) cout << tale.at(tale.size() - i - 1);
    reverse(S.begin(), S.end());
    cout << S;
    for(ll i = 0; i < head.size(); i++) cout << head.at(i);    
  }
  else {
    for(ll i = 0; i < head.size(); i++) cout << head.at(head.size() - i - 1);
    cout << S;
    for(ll i = 0; i < tale.size(); i++) cout << tale.at(i);    
  }
}