 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int MOD = 1e9 + 7;
 const int INF = 2147483647;
 // const ll INF = 1000000000000000000LL;
 
 int main(){
   int n;
   cin >> n;
   if(n==1){
       cout << 1 << endl;
       return 0;
   }
   vector<ll> x(n);
   vector<ll> y(n);
   rep(i,n){
       cin >> x[i] >> y[i];
   }
    map<pair<ll,ll>,ll> cur;
   rep(i,n){
       rep(j,n){
           if(i!=j){
               cur[make_pair(x[j]-x[i],
               y[j]-y[i])]++;
           }
       }
   }
   ll max = -INF;
   pair<ll,ll> max_pr;
   for(auto a:cur){
       if(max<a.second){
         max = a.second;
         max_pr = a.first;
       }
   }
   ll ans = n-max;
   cout << ans << endl;
   return 0;
 }