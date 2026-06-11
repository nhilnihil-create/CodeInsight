#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
#include<queue>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;

  vi vec(n);
  rep(i,n) cin >> vec.at(i);

  sort(vec.begin(), vec.end());
  int sum = 0;
  rep(i,k) sum += vec.at(i);

  cout << sum << endl;
}
