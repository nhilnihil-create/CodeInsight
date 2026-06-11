#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t A, B, C, D, minc, mind, dc, dd, mincd, dcd;
  cin >> A >> B >> C >> D;
  minc = (A % C == 0) ? A : (A / C + 1) * C;                            // Cで割り切れるA以上の最初の数
  dc = (minc <= B) ? (B - minc) / C + 1 : 0;                            // A以上、B以下でCで割り切れる数の個数
  mind = (A % D == 0) ? A : (A / D + 1) * D;                            // Dで割り切れるA以上の最初の数
  dd = (mind <= B) ? (B - mind) / D + 1 : 0;                            // A以上、B以下でDで割り切れる数の個数
  mincd = (A % lcm(C, D) == 0) ? A : ((A / lcm(C, D)) + 1) * lcm(C, D); // C*Dで割り切れるA以上の最初の数
  dcd = (mincd <= B) ? (B - mincd) / lcm(C, D) + 1 : 0;                 // A以上、B以下でC*Dで割り切れる数の個数
  cout << (B - A + 1) - dc - dd + dcd << endl;
}