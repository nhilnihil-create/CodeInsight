#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

string S;

int main(){
  cin >> S;
  switch (S[S.size() - 1]){
    case '2':
    case '4':
    case '5':
    case '7':
    case '9':
      cout << "hon" << endl;
      break;
    case '0':
    case '1':
    case '6':
    case '8':
      cout << "pon" << endl;
      break;
    case '3':
      cout << "bon" << endl;
      break;
  }
}
