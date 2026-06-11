#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long long a;
  double b;
  cin >> a >> b;
  long long nb = (long long)(100.0*b+0.2);
  long long ans = (a*nb)/100;
  cout << ans << endl;
  return 0;
}