#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
const int mod=1e9+7;
int main (){
  int n; cin >> n;
  for(int i = 1; i <= 50000; i++){
    int now = i * 1.08;
    if(now == n){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}

 
