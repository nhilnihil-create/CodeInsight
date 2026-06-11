#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(a>=k) ans++;
  }
  cout <<  ans << endl;
  return 0;
}
