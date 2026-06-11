#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
   ll a,v,b,w,t;
   cin >> a >> v >> b >> w >> t;
   if (v-w <= 0) {
      cout << "NO" << endl;
   } 
   else{
      if ((abs(a-b) + (v-w) -1)/(v-w) <= t) cout << "YES" << endl;
      else cout << "NO" << endl;
   }

   return 0;
   

}
