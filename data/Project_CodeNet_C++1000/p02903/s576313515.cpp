#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  vector<string> s(h,string(w,'0'));
  rep(i,b)rep(j,a)s[i][j] = '1';
  for(int i = b;i < h;i++)for(int j = w-1;j >= a;j--)s[i][j] = '1';
  rep(i,h)cout << s[i] << endl;

  



  return 0;
}