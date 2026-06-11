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
  ll n;
  cin >> n;
  string ans;
  while (n){
    n--;
    ans += 'a'+n%26;
    n /= 26;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
  }
