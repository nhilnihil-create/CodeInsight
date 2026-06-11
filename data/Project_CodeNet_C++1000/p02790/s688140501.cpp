#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int x = max(a,b);
  int y = min(a,b);
  rep(i,x) cout << y;
  cout << endl;
}
