#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  int n;
  cin >> n;
  vi a(n), b(n), c(n-1);
  rep(i, n)cin >> a[i];
  rep(i, n)cin >> b[i];
  rep(i, n-1)cin >> c[i];

  int sum=b[a[0]-1];
  for(int i=1; i<n; i++){  
    sum+=b[a[i]-1];
    if(a[i]-a[i-1]==1)sum+=c[a[i-1]-1];
    }

  cout << sum << endl;

  return 0;
}