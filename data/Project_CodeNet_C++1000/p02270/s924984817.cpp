#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)

const int MAX = 100000;

int function(int P, int k, int w[], int m)
{
  int j = 0;
  int c = 0;
  int nk = 0;
  int np = 0;
  while(nk < k){
    for(int i = j; i < m; i++, c++){
      np += w[i];
      if(np > P){
	np = 0;
	j = i;
	break;
      }
      if(i == m - 1)
	return m;
    }
    nk++;
  }
  return c;
}

int binarySearch(int key, int k, int w[], int m){
  int left = 0;
  int right = MAX * 10000;
  int mid;
  while(left + 1 < right){
    mid = (left + right) / 2;
    if(function(mid, k, w, m) < key)
      left = mid;
    else
      right = mid;
  }
  return right;
}

int main()
{
  int n, k;
  cin >> n >> k;
  int w[n];
  REP(i, n)
    cin >> w[i];
  cout << binarySearch(n, k, w, n) << endl;
}