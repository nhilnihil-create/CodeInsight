#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main() {
  int n;
  cin>>n;
  int ans=n/2;
  if (n%2==0) ans--;
  cout<<ans<<endl;
  return 0;
}