#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
const ll mod=1000000007;

main(){
  int n;cin >> n;
  int a[n];for(int i=0;i<n;i++) cin >> a[i];
  ll ans=0;
  for(int i=0;i<n-1;i++){
    if(a[i]>a[i+1]){
      int diff=0;
      diff=a[i] - a[i+1];
      a[i+1]+=diff;
      ans+=diff;
    }
  }
  cout << ans << endl;
  return 0;
}