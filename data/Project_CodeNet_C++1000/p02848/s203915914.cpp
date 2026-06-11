#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int shift;
   cin >> shift;
   string s;
   cin >> s;
   int n = s.length();
   for(int i = 0 ; i < n ; i++)
      cout << char('A' + (s[i] - 'A' + shift) % 26);
   return 0;
}
