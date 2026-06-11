#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b,n;
  cin >> a >> b >> n;
  int64_t x=min(n,b-1);
  int64_t ans=(int64_t)a*x/b-a*(int64_t)(x/b);
  cout << ans << endl;
}