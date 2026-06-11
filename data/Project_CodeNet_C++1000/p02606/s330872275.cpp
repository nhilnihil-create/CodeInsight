#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int l,r,d;
  cin >> l >> r >> d;

  cout << r/d - int((l-0.1)/d);
}