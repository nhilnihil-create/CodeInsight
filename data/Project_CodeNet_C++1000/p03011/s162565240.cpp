#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> d(3,0);
  cin >> d[0] >> d[1] >> d[2];
  sort(d.begin(),d.end());
  cout << d[0]+d[1] << endl;
}