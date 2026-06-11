#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  ll W, H, x, y; cin >> W >> H >> x >> y;
  double area = 0.5*H*W;
  int ex;
  if (H%2==0 && W%2==0 && 2*x==W && 2*y==H) ex = 1;
  else ex = 0;

  cout << fixed << setprecision(10);
  cout << area << " " << ex << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}

