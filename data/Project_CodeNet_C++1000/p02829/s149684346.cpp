#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

void output(int x, int y, int s, int t, int m){
  if(x==s&&y==t){
    cout << m << endl;
  }
}

int main() {
  int a,b;
  cin >> a >> b;
  output(a,b,1,2,3);
  output(a,b,2,1,3);
  output(a,b,2,3,1);
  output(a,b,3,2,1);
  output(a,b,1,3,2);
  output(a,b,3,1,2);

  return 0;

}