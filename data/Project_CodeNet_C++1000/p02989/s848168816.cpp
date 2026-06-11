#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<int> d(n);
  rep(i,n) cin >> d.at(i);

  sort(d.begin(), d.end());

  int center = n/2;
  cout << d.at(center)-d.at(center-1);
}