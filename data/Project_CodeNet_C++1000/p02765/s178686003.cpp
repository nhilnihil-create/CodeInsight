#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
   int n,r;
   cin >> n >> r;
   int ans = 0;
   if (n >= 10) ans = r;
   else ans = r + 100*(10-n);
   cout << ans << endl;


  
  return 0;
}
