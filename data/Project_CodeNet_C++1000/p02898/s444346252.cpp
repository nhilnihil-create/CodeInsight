#include <bits/stdc++.h>
#include<math.h>
using namespace std;
using ll = long long;

int main(){ 
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0 ; i< n ; i++){
       cin >> h[i];
    }
    int ans = 0;
    for(int i = 0; i< n; i++){
       if(h[i]>=k) ans++;
   }
   cout << ans << endl;
   return 0;
}