#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, mx;
  vector<int>vec, vec2;
  cin >> n;
  while(n--){
    cin >> a;
    vec.push_back(a);
    vec2.push_back(a);
  }
  sort(vec.rbegin(), vec.rend());
  // vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for(int i=0; i<vec2.size(); i++){
    if(vec2[i]<vec[0]){
      cout << vec[0] << endl;
    }
    else cout << vec[1] << endl;
  }
}
