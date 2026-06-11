#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long num, a, decide=0, first, sec;
  vector<long long> list;
  cin >> num;
  for (long long i=0; i<num; i++) {
    cin >> a;
    list.push_back(a);}
  sort(list.begin(), list.end());
  first = list[0];
  for (long long i=1; i<num; i++) {
    sec = list[i];
    if (sec==first) {cout << "NO"; decide=1; break;}
    first = sec;}
  if (decide==0) {cout << "YES";}}