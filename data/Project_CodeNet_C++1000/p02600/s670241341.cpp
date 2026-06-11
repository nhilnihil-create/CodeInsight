#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int a[] = {
400,
599,
8,
600,
799,
7,
800,
999,
6,
1000,
1199,
5,
1200,
1399,
4,
1400,
1599,
3,
1600,
1799,
2,
1800,
1999,
1
};

int main() {
   int n;
   cin >> n;
   for(int i=0; ; i+=3) {
      if(a[i] <= n && n <= a[i+1]) {
         printf("%d\n", a[i+2]);
         exit(0);
      }
   }
}
