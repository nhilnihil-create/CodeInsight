#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ll w,h; cin>>w>>h;
  ll x,y; cin>>x>>y;
  // 与えられたx,yがどこであろうと、(x,y)と長方形の中心を通る直線を引けば良い
  // この線が複数存在するのは、x,yが中心点であるときのみ
  ll area = w*h/2.0;
  int isMid = 0;
  if(x*2==w&&y*2==h) isMid = 1;
  if(w%2==1&&h%2==1) cout << area << ".5" << " " << isMid << endl;
  else cout << area << " " << isMid << endl;
}
