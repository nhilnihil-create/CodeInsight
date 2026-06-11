#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  if(n%2==0){
    cout << n/2 << endl;
  }
  else if(n%2==1){
    cout << n/2+1 << endl;
  }
  return 0;

}