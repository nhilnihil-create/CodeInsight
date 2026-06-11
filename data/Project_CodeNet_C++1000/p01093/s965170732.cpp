#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while( cin >> n, n ) {
    vector<int> vec(n);
    for(int i=0;i<n;++i) cin >> vec[i];
    sort(vec.begin(),vec.end());
    int mini = INT_MAX;
    for(int i=0;i<n-1;++i) {
      mini = min(mini,vec[i+1]-vec[i]);
    }
    cout << mini << endl;
  }
  return 0;
}