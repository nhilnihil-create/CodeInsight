//g++ -std=gnu++14 a.cpp
//#include <bits/stdc++.h>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N),B(N);
  rep(i,N)cin >> A[i] >> B[i];
  ll min,max;
  vector<ll> mi(N),ma(N);
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  if(N%2==1){
    min = A[(N+1)/2-1];
    max = B[(N+1)/2-1];
  }else{
    min = A[N/2-1]+A[N/2];
    max = B[N/2-1]+B[N/2];
  }
  cout << max - min + 1 << endl;

}
