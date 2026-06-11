#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
     cin >> n;
      long long sum = 0;
      vector<long long> v(n);
      for (int i = 0; i < n; i++) {
          cin >> v[i];
          sum+=v[i];
      }
      sort(v.begin(), v.end());
      
     reverse(v.begin(), v.end());
      int len = n;
     if(len == 1) {
         cout << 0;
         return 0;
     } else if(len == 2) {
         cout << v[0];
     }
     sum = v[0];
     int count = 2;
     for(int i = 1; i < n; i++){
             for(int j = 1 ; j <= 2; j++) {
                 sum += v[i];
                 count++;
                 if(count == len) {
                     cout << sum;
                     return 0;
                    //  break;
                 }
             }
     }
    return 0;
}