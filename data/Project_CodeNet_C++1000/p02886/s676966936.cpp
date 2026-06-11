#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using ll = long long;
int main(){
  int a;
  cin >> a;
  vector<int>tako(a);
  rep(i,a)cin >> tako[i];
  ll sum = 0;
  rep(i,a)for(int j = i+1;j<a;j++)sum += tako[i] * tako[j];
  cout << sum << endl;
}
