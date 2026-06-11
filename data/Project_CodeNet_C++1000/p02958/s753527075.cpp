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

  int n, cnt=0;
  cin >> n;
  vi p(n);
  rep(i, n){
    cin >> p[i];
    if(p[i]!=i+1)cnt++;
  }

  printf(cnt==0||cnt==2 ? "YES\n" : "NO\n");

  return 0;
}