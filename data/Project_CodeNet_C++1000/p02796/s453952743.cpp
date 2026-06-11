#include<iostream>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;
int n, m, ans=0;

int main(){
  cin >> n;
  vector<int> x(n);
  vector<int> l(n);
  vector<P> ps(n);
  for(int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    x[i] = a, l[i] = b;
    ps[i] = P(a+b, a-b);
  }
  sort(ps.begin(), ps.end());
  int cur = -1000000000;
  for(int i=0; i<n; i++){
    if(cur <= ps[i].second){
      ans++;
      cur = ps[i].first;
    }
  }
  
  cout << ans << endl;
  return 0;
}