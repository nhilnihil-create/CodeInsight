#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
 
int main() {
  string S, T, U;
  int A, B;
  cin >> S >> T >> A >> B >> U;
  
  if(U==S) A--;
  else B--;
  
  cout << A << " " << B << endl;
}