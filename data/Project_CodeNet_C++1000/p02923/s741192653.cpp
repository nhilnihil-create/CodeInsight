#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> h(n);
  rep(i,n) cin >> h.at(i);

  int count=0;
  int maxc=0;

  rep(i,n-1){
    if(h.at(i)>=h.at(i+1))count++;
    else {maxc=max(maxc,count); count=0;}
  }
  maxc = max(maxc, count);
  cout << maxc;
}