#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using ll = long long;
int main(){
  int a,b;
  double sum=0;
  cin >> a;
  rep(i,a){cin >> b;sum += 1.0/b;}
   cout << fixed << setprecision(15) << 1.0/sum << endl;
  return 0;
}
