#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  if(a<b) cout << "0" << endl;
  else{
    vector<int> vec(a);
  for(int i=0;i<a;i++){
   cin >> vec.at(i);
  }
    sort(vec.begin(), vec.end());
   long int count = 0;
    for(int j=0;j<a-b;j++){
    count += vec.at(j);
    }
  cout << count << endl;
    return 0;
  }
}