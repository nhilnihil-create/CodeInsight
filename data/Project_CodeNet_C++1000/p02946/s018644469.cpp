#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int K, X;
  cin >> K >> X;
  int left, right;
  left = X-K+1;
  right = X+K-1;
  repi(i, left, right){
    cout << i << " ";
  }
  cout << right << endl;
}