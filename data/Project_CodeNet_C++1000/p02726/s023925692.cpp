#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,x,y;
  cin >> n >> x >> y;
  vector<int> a(n,0);
  for(int i=1;i<n;i++){
    for(int j=i+1;j<n+1;j++){
      int to_x=abs(x-i);
      int to_y=abs(y-j);
      a[min(to_x+to_y+1,j-i)]++;
    }
  }
  for(int i=1;i<n;i++){
    cout << a[i] << "\n";
  }
  return 0;
}