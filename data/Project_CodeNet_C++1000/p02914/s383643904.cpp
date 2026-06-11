#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
typedef unsigned long long ll;
bitset<61> a[100005];

int main() {
  int n;
  cin >> n;
  bitset<61> tmp(0);
  for(int i = 0; i < n; i++) {
    ll A; cin >> A;
    a[i] = A;
    tmp ^= A;
  
  }
  
   for(int i = 0; i < n; i++) {
    for(int j = 0; j <= 65; j++) {
      if(tmp[j] == 1) {
	a[i][j] = 0;
      }
    }
  }

  
   int rank = 0;
   for(int i = 60; i >= 0; i--) {
     int j = rank;
     while(j < n && a[j][i] == 0) j++;
     if(j == n) continue;
     swap(a[rank],a[j]);
     for(int k = 0; k < n; k++) {
       if(k == rank) continue;
       if(a[k][i] == 0) continue;
       a[k] ^= a[rank];
     }
     rank++;
   }

   for(int i = 1; i < n; i++) a[0] ^= a[i];
     a[0] <<= 1;
     cout << a[0].to_ullong() + tmp.to_ullong() << endl;
      
}
