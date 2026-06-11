#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 1001;
bool visited[N][N];

void solveCase() {
   int n;
   cin >> n;
   vector <int> a(n);
   int x = 0;
   for(int i = 0; i < n; i++) {
      cin >> a[i];
      x ^= a[i];
   }

   cout << ((x == 0)?"Yes": "No") << endl;
}


int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solveCase();
   }
 
   return 0;
}
