#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll a;
  string b;
  cin >> a >> b;
  
  int n = b.size();
  
  REP(i,n){
	if(b[i] == '.'){
      b.erase(i,1);
    }
  }
  
  int bi = atoi(b.c_str());
  
  ll c = a * bi / 100;
  cout << c << endl;
  
}
