#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n , k , s;
   cin >> n >> k >> s;
   if(s == mod - 7){
      for(int i = 0 ; i < k ; i++)
         cout << mod - 7 << " ";
      for(int i = 0 ; i < n - k ; i++)
         cout << 1 << " ";
      return 0;
   }
   for(int i = 0 ; i < k ; i++)
      cout << s << " ";
   for(int i = 0 ; i < n - k ; i++)
      cout << mod - 7 << " ";
   return 0;
}
