#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  long long Namount, amt, inpurt, len, fin=0, start=0;
  cin >> Namount;
  vector<long long> list;
  amt = (Namount*(Namount-1))/2;
  for (int i=0; i<Namount;i++) {
    cin >> inpurt;
    list.push_back(inpurt);}
  len = list.size();
  for (int t=0; t<len; t++){
    start=0;
    for (int i=t+1; i<len; i++) {
      start+=list[i];}
    fin+=list[t]*start;}
  cout << fin;}