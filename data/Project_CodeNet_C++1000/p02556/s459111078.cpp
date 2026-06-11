#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> vx(n);
  vector<int> vy(n);
  
  rep(i,n){
    int x,y;
    cin >> x >> y;
    vx[i] = x+y;
    vy[i] = x-y;
  }
  
  int xmax = *max_element(all(vx))-*min_element(all(vx));
  int ymax = *max_element(all(vy))-*min_element(all(vy));
  
  cout << max(xmax,ymax) << endl;
}
