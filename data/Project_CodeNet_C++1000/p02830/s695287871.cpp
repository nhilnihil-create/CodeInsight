#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
 
int main () {
int N ;
cin >> N ;
string S, T;
cin >> S >> T;
string newstring ;
rep (i, N) {
  newstring.push_back(S[i]);
  newstring.push_back(T[i]);}
cout << newstring << endl;
return 0;
}