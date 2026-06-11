#include <bits/stdc++.h>
#define rep2(i,x,y) for (int i = x; i < (y); ++i)
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  int n,d;
  cin >> n >> d;
  double x, y;
  int count = 0;
  rep(i, n){
    cin >> x >> y;
    double tmp = (x*x) + (y*y);
    if(sqrt(tmp) <= d){
      count++;
    }
  }
  cout << count << endl;
  
  
  return 0;
}