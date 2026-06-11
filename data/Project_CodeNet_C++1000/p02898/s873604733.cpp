#include <bits/stdc++.h> 
using namespace std; 
 
int main() {
  int n, k, *height, i, answer = 0;
  cin >> n >> k;
  height = new int[n];
  for(i = 0; i < n; i++)
    cin >> height[i];
  for(i = 0; i < n; i++) {
    if(height[i] >= k) 
      answer++;
  }
  delete []height;
  height = NULL;
  cout << answer;
  return 0;
}