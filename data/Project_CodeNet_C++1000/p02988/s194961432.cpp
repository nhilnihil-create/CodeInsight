#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<long long> list;
  long long num,a,fin=0;
  cin >> num;
  for (long long i=0; i<num; i++) {
    cin >> a;
    list.push_back(a);}
  for (long long i=1; i<num-1; i++) {
    if (list[i]>list[i-1] && list[i]<list[i+1]) {
      fin++;}
    else if (list[i]<list[i-1] && list[i]>list[i+1]) {
      fin++;}}
  cout << fin;}