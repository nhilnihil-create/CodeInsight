#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int h , w , n;
   cin >> h >> w >> n;
   if(h < w)
      swap(h , w);
   cout << n / h + (n % h > 0);
   return 0;
}
