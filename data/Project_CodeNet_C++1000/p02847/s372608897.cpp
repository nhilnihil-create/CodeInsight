#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  map<string , int> mp = {
    {"SUN", 7},
    {"MON", 6},
    {"TUE", 5},
    {"WED", 4},
    {"THU", 3},
    {"FRI", 2},
    {"SAT", 1}};
  string s; cin >> s;
  cout << mp[s] << endl;
  return 0;
}