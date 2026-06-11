#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p;

  for(int i = 0; i < n; i++){
    int tmp;
    cin >>tmp;
    p.push_back(tmp);
  }

  int cnt = 0;
  int min = *max_element(p.begin(), p.end()) + 1;
  for(int i = 0; i < n; i++){
    if(p[i] < min) {
      min = p[i];
      cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}
