#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;
int main(){
  int n;
  vector<int> x;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    x.push_back(tmp);
  }

  int p = round((double)accumulate(x.begin(), x.end(), 0) / (double)x.size());
 
  int hp = 0; 
  for(int i = 0; i < n; i++) {
    hp += pow((x[i] - p), 2);
  }

  cout << hp << endl;
  return 0;
}
