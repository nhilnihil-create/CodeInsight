#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <map>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

#define INF 1<<30

int main(){
  long long X, K, D;
  cin >> X >> K >> D;
  X = abs(X);
  if (X / D > K)
  {
    cout << X - K * D << endl;
  }
  else{
    if((K-X/D)%2==0){
      cout << X - X/D * D << endl;
    }
    else{
      cout << -(X - (X/D+1) * D) << endl;
    }
  }
  return 0;
}