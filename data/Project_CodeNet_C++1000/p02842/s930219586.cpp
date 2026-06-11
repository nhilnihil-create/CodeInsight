#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;

  cin >> N;
  for(int i=1;i<=N;++i){
    int s = (int)(i*1.08);
    if(s==N){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}
