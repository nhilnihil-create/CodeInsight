#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main() {
  int n, k, num, ans = 0;
  cin >> n >> k;
  vector<int> d(n);
  rep(i,n) d[i] = 0;
  rep(i,k){
    cin >> num;
    rep(j,num){
      int a;
      cin >> a;
      d[a - 1]++;
    }
  }
  rep(i,n) if(d[i] == 0) ans++;
  cout << ans << endl;
}