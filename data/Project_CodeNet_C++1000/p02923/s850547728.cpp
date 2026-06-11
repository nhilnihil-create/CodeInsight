#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  int N;
  cin >> N;
  int H[N];
  rep(i,N)
    cin >> H[i];
  int res = 0;
  int a = 0;
  rep(i,N-1){
    if (H[i]>=H[i+1])
      a++;
    else{
      res = max(a,res);
      a = 0;
    }
  }
  cout << max(a,res) << endl;
}