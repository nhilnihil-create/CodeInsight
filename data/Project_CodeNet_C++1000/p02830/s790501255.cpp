#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
   int n;
   cin >> n;
   string s,t;
   cin >> s >> t;
   string ans = "";
   rep(i,n){
      ans += s[i];
      ans += t[i];
   }
   cout << ans << endl;
}
