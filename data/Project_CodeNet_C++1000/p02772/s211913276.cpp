#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a[10000],b[10000];
  int n, num = 0;
  cin >> n;
  rep(i,n) {
    cin >> a[i];
    if(a[i] % 2 == 0) {
      b[num] = a[i];
      num++;
    }
  }
  string s = "APPROVED";
  rep(i,num){
    if(b[i] % 3 != 0 && b[i] %5 != 0){
      s = "DENIED";
    }
  }
  cout << s << endl;

  return 0;
}