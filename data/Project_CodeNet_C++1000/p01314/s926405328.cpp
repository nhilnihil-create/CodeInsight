#include<iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

int main() {
  for(;;) {
    int N; cin >> N; if( N == 0 ) break;
    int ans = 0;
    for(int start = 1; start < N; start++) {
      int sum = 0;
      for(int i = 0; sum < N; i++)
        sum += start + i;
      if( sum == N )
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}