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
  cin >> n;
  vi p(n);
  rep(i ,n)cin >>p[i];

  int cnt=0;
  rep(i, n-2){
    if(p[i]==max(p[i], max(p[i+1], p[i+2]))&&p[i+2]==min(p[i], min(p[i+1], p[i+2])))cnt++;
    if(p[i+2]==max(p[i], max(p[i+1], p[i+2]))&&p[i]==min(p[i], min(p[i+1], p[i+2])))cnt++;
  }

  cout << cnt << endl;

  return 0;
}