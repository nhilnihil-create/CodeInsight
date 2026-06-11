#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  ll s;
  cin >> s;
  ll x1=s/1000000000+1;
  ll x2=x1*1000000000-s;
  if(x1!=1000000001)
    cout << x1 << " " << 1 << " " <<x2 <<" " << 1000000000 << " " <<0 << " " <<0<<endl;
  else
    cout << 1000000000 << " " << 0 << " " <<0 <<" " << 1000000000 << " " <<0 << " " <<0<<endl;
}