#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <map>
using namespace std;
typedef long long ll;
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
  int n;
  cin >> n;

  FOR(i,1,50000){
    if((int)(i*1.08)==n){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}