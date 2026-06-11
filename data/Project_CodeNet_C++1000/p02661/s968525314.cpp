#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include<vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  int i;
  ll a[n+10],b[n+10];
  for(i=0;i<n;i++){
    cin >> a[i] >> b[i];
  }
  sort(a,a+n);
  sort(b,b+n);
  int ans = 0;
  if(n%2 == 1){
    int l = a[n/2];
    int r = b[n/2];
    ans = r-l+1;
  }else{
    int l2 = a[n/2-1]+a[n/2];
    int r2 = b[n/2-1]+b[n/2];
    ans = r2-l2+1;
  }
  cout << ans << endl;
}
