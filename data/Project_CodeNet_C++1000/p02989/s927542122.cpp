#define _GLIBCXX_DEBUG
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int d[N];
  
  for(int i=0; i<N; i++) cin >> d[i];

  sort(d, d + SIZE_OF_ARRAY(d));

  cout << d[N/2]-d[N/2-1] << endl;

  return 0;
}
