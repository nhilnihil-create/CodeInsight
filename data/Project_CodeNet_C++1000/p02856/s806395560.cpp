#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
// #include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int M;
  cin >> M;
  ll L=0,sum=0;
  for(int i=0; i<M; i++){
    ll d,c;
    cin >> d >> c;
    L += c;
    sum += d*c;
  }
  cout << L-1 + (sum-1)/9 << endl;
  return 0;
}
