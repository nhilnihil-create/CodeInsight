#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  double w,h; cin>>w>>h;
  double x,y; cin>>x>>y;
  cout <<  setprecision(10) << (double)(w*h)/2.0 << endl;
  if (x == (double)w/2 && y == (double)h/2) cout << 1 << endl;
  else cout << 0 << endl;
}