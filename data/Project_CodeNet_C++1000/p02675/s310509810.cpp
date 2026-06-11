#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 2e9
#define ALL(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  switch (n%10){
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      cout << "hon" << endl;
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      cout << "pon" << endl;
      break;
    default:
      cout << "bon" << endl;
      break;
  }
  return 0;
}