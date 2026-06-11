#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const ll INF = 1001001001;

int main(){
  int n;
  cin >> n;
  rep(i,50000){
    if (int(i*1.08) == n) {
      cout << i <<endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}
