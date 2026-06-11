#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
   int n; cin >> n;
   int a[n]; rep(i,n) cin >> a[i]; 
   bool positive = false,negative = false;
   rep(i,n){
       if(a[i] > 0) positive = true;
       if(a[i] <= 0) negative = true;
   }
   ll ans = 0;
   sort(a,a+n);
   ll x = a[0], y = a[n-1];
   queue<int> n_que;
   queue<int> p_que;
   for(int i = 1; i < n-1; i++){
       if(a[i] <= 0) n_que.push(a[i]);
       else p_que.push(a[i]);
   }
   if(positive && negative){
       rep(i,n) ans += abs(a[i]);
       cout << ans << endl;
       while(!p_que.empty()){
           int k = p_que.front(); p_que.pop();
           cout << x << ' ' << k << endl;
           x -= k;
       }
       cout << y << ' ' << x << endl;
       y -= x;
       while(!n_que.empty()){
           int k = n_que.front(); n_que.pop();
           cout << y << ' ' << k << endl;
           y -= k;
       }
   }else if(positive){
       rep(i,n) ans += a[i];
       cout << ans - 2 * a[0] << endl;
       while(!p_que.empty()){
           int k = p_que.front(); p_que.pop();
           cout << x << ' ' << k << endl;
           x -= k;
       }
       cout << y << ' ' << x << endl;
   }else{
       rep(i,n) ans += abs(a[i]);
       cout << ans + 2 * a[n-1] << endl;
       while(!n_que.empty()){
           int k = n_que.front(); n_que.pop();
           cout << y << ' ' << k << endl;
           y -= k;
       }
       cout << y << ' ' << x << endl; 
   }  
}