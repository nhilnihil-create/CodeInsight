#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   string s[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
   string t;
   cin >> t;
   for(int i = 0 ; i < 7 ; i++)
      if(t == s[i])
         cout << 7 - i;
   return 0;
}
