// AtCoder Beginner Contest 150
// Problem B - Count ABC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll N;
   string s = " ";
   cin >> N >> s;
   ll ans = 0;
   for(int i = 0; i <= N-3; ++i){
      if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
         ++ans;
      }
   }
   cout << ans << '\n';
   return 0;
}