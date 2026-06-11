#include <bits/stdc++.h>
using namespace std;
int H1, H2, M1, M2, K;

int main()
{
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  M1 += H1 * 60;
  M2 += H2 * 60;
  /*  if(M1 > M2){
    M2 +=1440;
  } */

  int ans = M2 - M1 - K;
  if (ans <= 0)
  {
    ans = 0;
  }

  cout << ans << endl;
}