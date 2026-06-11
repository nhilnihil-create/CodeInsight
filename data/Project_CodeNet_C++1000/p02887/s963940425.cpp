#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
   int n;
   string s;
   cin >> n >> s;
   int ans = 0;
   for(int i = 0; i < n - 1; i++){
      if(s[i] != s[i + 1]) ++ans;
   }
   ans++;
   cout << ans << endl;
   return 0;
}