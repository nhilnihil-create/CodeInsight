#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

string S;
bool flag = false;

int main(){
  cin >> S;
  rep(i, 3){
    if (S[i]==S[i+1]) flag=true;
  }
  if (flag==false) cout << "Good" << endl;
  else cout << "Bad" << endl;
}