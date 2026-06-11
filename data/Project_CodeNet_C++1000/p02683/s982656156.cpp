#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
int n,m,x;
cin >> n >> m >> x;
vector<vector<int>> a(n,vector<int>(m+1));
rep(i,n)rep(j,m+1)cin >> a.at(i).at(j);
vector<int> b;
for(int tmp = 0; tmp < (1 << n); tmp++){
  bitset<12> s(tmp);
  int sum = 0;
  vector<int> d(m);
  rep(i,n)if(s.test(i)){
      sum += a.at(i).at(0);
      rep(j,m) d.at(j)+=a.at(i).at(j+1);
    }
  //条件を満たすかどうかの確認
  bool flag = true;
  rep(i,m)if(d.at(i) < x) flag = false;
  //満たすならbに入れる
  if(flag) b.push_back(sum);
  
}
  if(b.size() == 0){
    cout << -1 << endl;
    return 0;
  }
sort(b.begin(),b.end());
cout << b.at(0) << endl;

} 