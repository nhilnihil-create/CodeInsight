#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1000000000; // 10^9

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll h,w;
  cin>>h>>w;

  // The bishop can not move digonally when the board is a line. 
  if(h == 1 || w == 1) {
    cout << 1 << '\n';    
    return 0;
  }
  
  // The bishop starts on a valid square (i.e. a specific colored square). 
  // Every other square is then also valid.
  // No. of valid squares is half the squares when h*w is even.
  // No. of valid squares is rounded up (i.e. h*w+1) when h*w is odd.
  cout <<  (h*w+1)/2 << '\n';

  return 0;
}
