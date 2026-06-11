#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  vector<int> vec_a;
  int diff;
  int diff_min;
  
  while (1) {
    cin >> n;
    if (n == 0) break;
    
    vec_a.clear();
    while (n--) {
      int a;
      cin >> a;
      vec_a.push_back(a);
    }
    
    sort(vec_a.begin(), vec_a.end());
    
    diff_min = 1000000;
    for (int i = 1; i != vec_a.size(); i++) {
      diff = vec_a.at(i) - vec_a.at(i - 1);
      if (diff < diff_min) diff_min = diff;
    }

    cout << diff_min << endl;
  }
}
      
  

