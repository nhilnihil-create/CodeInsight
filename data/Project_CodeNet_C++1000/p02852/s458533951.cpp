#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n , m;
   cin >> n >> m;
   string s;
   cin >> s;
   int cur = n , lst = -1 , ch = n - 1;
   vector <int> ans;
   while(cur != 0){
      for(int i = ch ; i >= max(0 , cur - m) ; i--){
         if(s[i] == '0')
            lst = i;
         ch = i - 1;
      }
      if(lst == -1)
         return cout << -1 , 0;
      ans.push_back(cur - lst);
      cur = lst;
      lst = -1;
   }
   reverse(ans.begin() , ans.end());
   for(int x : ans)
      cout << x << " ";
   return 0;
}
