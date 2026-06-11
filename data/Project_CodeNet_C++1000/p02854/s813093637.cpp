#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;
typedef long long llint;
typedef long double ld;
#define inf 1e18


llint n;
llint r[200005];
llint a[200005];
void solve(){
	cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(i==0)r[i]=a[i];
    else{
      r[i]=r[i-1]+a[i];
    }
  }
  llint ans=10000000007;
  for(int i=0;i<n;i++){
    llint s1=r[i];
    llint s2=r[n-1]-r[i];
    llint dif=abs(s1-s2);
    ans=min(ans,dif);
  }
  cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
