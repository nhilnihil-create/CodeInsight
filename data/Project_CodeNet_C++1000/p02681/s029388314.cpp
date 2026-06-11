#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s1,s2;
  cin >> s1 >> s2;
  
  s2.pop_back();
  
  
  if(s1 == s2){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
}