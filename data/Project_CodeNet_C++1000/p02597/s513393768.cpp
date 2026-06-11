#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  string S;
  cin >> N >> S;

  int r = 0,w = 0;

  for(int i = 0;i < N;i++) {
    if(S[i] == 'R') r++;
    else w++;
  }

  int ans = r;
  w = 0;

  for(int i = 0;i < N;i++) {
    if(S[i] == 'R') r--;
    else w++;

    ans = min(ans,max(r,w));
  }

  cout << ans << endl;


}
