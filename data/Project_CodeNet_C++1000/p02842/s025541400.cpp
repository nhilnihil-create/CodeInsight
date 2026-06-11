#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  int ans=0;
  for(int i=1; i<50000; i++){
    double cnt = double(i)*1.08;
    if(n==int(floor(cnt))) ans = i;
  }
  if(ans==0) cout << ":(" << endl;
  else cout << ans << endl;
  return 0;
}
