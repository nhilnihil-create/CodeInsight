#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  int n;
  cin >> n;
  VI d(n);
  rep(i,n){
      cin >> d.at(i);
    }
    sort(d.begin(),d.end());
  int ans=d.at(n/2) - d.at((n/2)-1);
  cout << ans << endl;  
}