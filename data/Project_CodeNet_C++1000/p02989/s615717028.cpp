#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
   int n;
   cin >> n;
   vector<int> a(n);
   vector<int> t(100001);
   for(int i = 0;i < n;i++){
       cin >> a[i];
       t[a[i]]++;
   }
   int ans = 0;
   for(int i = 1;i <= 100000;i++){
       t[i] += t[i - 1];
       if(t[i] == n / 2)ans++;
   }
   cout << ans << endl;
   
}
