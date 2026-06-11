#include<bits/stdc++.h>
#define rep(i,x) for(int i=0; i<x; i++)
typedef long long ll;
using namespace std;

int main(){
  int h1,m1,h2,m2, k;
  cin >> h1>>m1>> h2>>m2>>k;

  int cost = (h2*60+m2) - (h1*60+m1);
  int ans = max(0, cost-k);
  cout << ans <<endl;
}
