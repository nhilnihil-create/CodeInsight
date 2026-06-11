#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = s.size();
  
  if(n <= k){
	cout << s << endl;
    return 0;
  }
  else{
    REP(i,k){
	  cout << s[i];
    }
  }
  cout << "..." << endl;
}
