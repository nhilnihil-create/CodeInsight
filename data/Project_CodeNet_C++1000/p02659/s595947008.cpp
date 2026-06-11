#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = (a); i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  ll a; double b;
  cin >> a >> b;
  ll aa = a;
  int bb = b*100+0.1;
  printf("%lld\n",(aa*bb)/100);
  return 0;
}
