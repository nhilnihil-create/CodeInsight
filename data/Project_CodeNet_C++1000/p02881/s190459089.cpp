#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());

    return ret;
}

int main(){

  ll n;
  cin >> n;
  ll ans = 0;
  vector<long long> ret = divisor(n);

  ll p;
  if(ret.size() % 2 == 0){
    p = ret.size()/2;
    cout << ret.at(p-1) + ret.at(p) -2 << endl;
  } else {
    p = ret.size()/2 + 1;
    cout << ret.at(p-1) * 2 -2 << endl;
  }

  return 0;
}