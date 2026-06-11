#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
    cin >> vec.at(i);
  sort(vec.begin(),vec.end());
  int a = n/2;
  int big = vec.at(a);
  int small = vec.at(a-1);
  if(big == small)
    cout << 0;
  else
    cout << big-small;
}