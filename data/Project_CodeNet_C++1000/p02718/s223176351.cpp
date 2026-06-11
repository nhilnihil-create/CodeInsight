#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,sum;
  cin >> n >> m;
  sum = 0;
  vector<int> vec(n);
  for(int i=0;i<n;i++){
    cin >> vec.at(i);
  }
  for(int i=0;i<n;i++){
    sum += vec.at(i);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  if(sum % (4*m) == 0){
    if(vec.at(m-1) < sum/(4*m))
      cout << "No";
    else
      cout << "Yes";
  }
  else{
    if(vec.at(m-1) <= sum/(4*m))
      cout << "No";
    else
      cout << "Yes";
  }
}