#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

const ll MAX = 300000;
bool isPrime[MAX];
void makePrime(){
  for (ll i = 0; i < MAX; i++){
    isPrime[i] = true;
  }
  for (ll i = 2; i * i < MAX + 1; i++){
    if(isPrime[i]){
      for (ll j = 2 * i; j < MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return;
}

int main()
{
  makePrime();
  int n;
  while(cin>>n,n) {
    int ans = 0;
    FOR(i,n+1,2*n+1) if(isPrime[i]) ans++;
    cout << ans << endl;
  }
  return 0;
}