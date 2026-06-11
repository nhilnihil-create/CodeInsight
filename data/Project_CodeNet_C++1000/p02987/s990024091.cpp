#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char>vec(4);
  cin  >> vec[0] >> vec[1] >> vec[2] >> vec[3];
  sort(vec.begin(),vec.end());
  if(vec[0] == vec[1] && vec[1] != vec[2] && vec[2] == vec[3]){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    cout  << "No" << endl;
  }
}
