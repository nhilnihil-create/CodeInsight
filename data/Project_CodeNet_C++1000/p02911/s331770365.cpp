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

int main(){

  int N, K ,Q, A;
  cin >> N >> K >>Q;

  map<int,int>m;
  for (int i = 0; i < N; i++) {
    m[i] = K;
  }

  vector<int> vec(Q);
  for (int q = 0; q < Q; q++) {
    cin >> A;
    m[A-1]++;
  }


  for(auto i = m.begin(); i != m.end(); i++) {
    i->second -= Q;
  }

  for(auto i = m.begin(); i != m.end(); i++) {
    if(i->second > 0){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}