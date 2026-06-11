#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
ll cnt =0,ans=0;

int main(){
   string s,t;
   cin >> s >> t;
   int n = s.size(), m=t.size();
   ans = INF;
   for(int i=0;i<=n-m;i++){
       cnt = 0;
       for(int j=0;j<m;j++){
           if(s.at(i+j) != t.at(j))
           cnt++;
       }
       if(cnt < ans) ans = cnt ;
   }
   cout << ans << endl;
}