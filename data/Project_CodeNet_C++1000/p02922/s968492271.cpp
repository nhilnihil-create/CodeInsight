#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  int a, b;
  cin >> a >> b;

  if((b-1)%(a-1)==0)cout << (b-1)/(a-1) << endl;
  else cout << (b-1)/(a-1)+1 << endl;

  return 0;
}