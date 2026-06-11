#include <bits/stdc++.h>
using namespace std;
int main(){
   long x; cin >> x;
   long y = x%100;
   long cnt = 0;
   for(int i=5;i>0;i--){
   cnt += y/i; y %= i;
   }
   if(cnt > x/100)cout << 0 << endl;
   else cout << 1 << endl;
}    