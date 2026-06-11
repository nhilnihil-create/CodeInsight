#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 2;
ll a[N];
int main(){
   int n, m;
   cin >> n >> m;
   priority_queue<int> pq;
   for(int i = 1; i <= n; i++){
      cin >> a[i];
      pq.push(a[i]);
   }
  
   while(m--){
     int x = pq.top();
     pq.pop();
     pq.push(x / 2);
   }
  
   ll ans = 0LL;
   while(!pq.empty()){
      ans += pq.top();
      pq.pop();
   }
  
   cout << ans;
 
   return 0;
}