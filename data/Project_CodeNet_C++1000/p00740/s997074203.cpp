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

int main()
{
  while(1) {
    int n, p;
    cin >> n >> p;
    if(n == 0) break;
    int num[n];
    FOR(i,0,n) num[i] = 0;
    int wan = p;
    FOR(i,0,1000006) {
      int now = i % n;
      if(wan > 0) {
        wan--;
        num[now]++;
        if(num[now] == p) {
          cout << now << endl;
          break;
        }
      } else {
        wan = num[now];
        num[now] = 0;
      }
    }
  }
  return 0;
}