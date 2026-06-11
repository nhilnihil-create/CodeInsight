#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int n,m;
  cin >> n >> m ;
  int k=n*(n-1)/2;
  int f=m*(m-1)/2;
  cout << k+f << endl;
  return 0;

}