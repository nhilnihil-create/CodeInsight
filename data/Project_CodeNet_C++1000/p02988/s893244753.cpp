#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  std::vector<int> vec(n);
  rep(i,n) cin >> vec.at(i);
  int cnt = 0;
  rep(i,n-2) {
    std::vector<int> v = 	vector(vec.begin() + i, vec.begin()+ i + 3);
    sort(v.begin(),v.end());
    if (vec.at(i+1) == v.at(1)) cnt++;
  }
  cout << cnt << endl;
}
