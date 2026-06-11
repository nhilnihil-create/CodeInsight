#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;

  int ans=1;
  rep(i, n-1)if(s[i]!=s[i+1])ans++;

  cout << ans  << endl;

  return 0;
}