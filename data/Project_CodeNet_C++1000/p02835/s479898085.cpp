#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main() {
  string Ans;
  vector<int> Num(3);
  REP(i,3) cin>> Num[i];
  Ans=Num.at(0)+Num.at(1)+Num.at(2)>=22?"bust":"win";
  cout << Ans << '\n';
  return 0;
}
