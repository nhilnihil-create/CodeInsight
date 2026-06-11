#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k, x;
  cin >> k >> x;

  for(int i=x-k+1; i<x+k-1; i++)cout << i << " ";
  cout << x+k-1 << endl;

  return 0;
}