#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int p[3];
  int ans=0;
  cin >> p[0]>>p[1]>>p[2];
  ans = p[0]+p[1]+p[2]-max(p[0],max(p[1],p[2]));
  cout << ans;
}
