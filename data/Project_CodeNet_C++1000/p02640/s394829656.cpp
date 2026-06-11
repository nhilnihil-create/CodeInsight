#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
int main(){
  int x,y;
  cin >> x >> y;
  bool can = false;
  rep(i,x+1){
    if(i*2+(x-i)*4==y) can = true;
  }
  if(can){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
