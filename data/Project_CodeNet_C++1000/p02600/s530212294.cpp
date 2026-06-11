#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
template< typename T = long long >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}
template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

int main(){
  int x;
  cin>>x;
  cout<<10-x/200<<endl;
}
