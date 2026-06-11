#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

   int n;
   cin >> n;
   int cur = 1, x;
   for(int i = 0; i < n; i++){
       cin >> x;
       if(x == cur) cur++;
   }
   if(cur == 1){
       cout << -1 << endl;
   } else{
       --cur;
       cout << n - cur << endl;
   }
   return 0;
}
