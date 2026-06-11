#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int main() {
  vector<int> arr(MAX,0);
  int num;
  while(cin >> num) {
    arr[num]++;
  }
  int mode_max = 0;
  for(int i=0;i<MAX;i++) {
    mode_max = max(mode_max,arr[i]);
  }
  for(int i=0;i<MAX;i++) {
    if(arr[i] == mode_max) {
      cout << i << endl;
    }
  }
}