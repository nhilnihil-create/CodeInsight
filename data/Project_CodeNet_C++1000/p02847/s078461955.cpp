#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  string S;
  cin >> S;
  if(S=="SUN") cout << 7 << endl;
  if(S=="SAT") cout << 1 << endl;
  if(S=="FRI") cout << 2 << endl;
  if(S=="THU") cout << 3 << endl;
  if(S=="WED") cout << 4 << endl;
  if(S=="TUE") cout << 5 << endl;
  if(S=="MON") cout << 6 << endl;
  
  return 0;
}

