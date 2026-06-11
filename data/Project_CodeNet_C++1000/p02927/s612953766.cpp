#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,m,d;
string s,t;

int main() {
  cin >> m >> d;
  int ans=0;
  rep(i,m+1)rep(j,d+1){
    int a=j%10,b=j/10;
    if(a>=2 && b>=2 && a*b==i) ans++;
  }
  cout << ans << endl;
}