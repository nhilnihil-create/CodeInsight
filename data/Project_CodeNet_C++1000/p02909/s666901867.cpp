#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
   string s;
   cin >> s;
   string ans;
   if(s == "Sunny") ans = "Cloudy";
   else if(s == "Cloudy") ans = "Rainy";
   else ans = "Sunny";
   cout << ans << endl;
  return 0;
}