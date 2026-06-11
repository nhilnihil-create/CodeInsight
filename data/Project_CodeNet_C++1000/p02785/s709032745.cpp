#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  
  sort(h.begin(), h.end());
  reverse(h.begin(), h.end());
  
  long sumH = 0;
  for (int i = k; i < n; i++) { // 体力の降順にソートしてk番目までとばし、体力の総和をとる
    sumH += h.at(i);
  }
  
  cout << sumH << endl;
}