#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const int SIZE = 100000;
int dp[3][SIZE];
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, k;cin>>n>>k;
   int r, s, p;cin>>r>>s>>p;
   string t;cin>>t;
   vector<bool> success;
   int ans = 0;
   for (int i=0; i<n; i++)
   {
      switch (t[i])
      {
      case 'r':
         if (i-k<0){
            ans+=p;
            success.push_back(true);
         }
         else if(t[i-k]!='r' || success[i-k]==false){
            ans+=p;
            success.push_back(true);
         }
         else success.push_back(false);
         break;
      case 's':
         if (i-k<0){
            ans+=r;
            success.push_back(true);
         }
         else if(t[i-k]!='s' || success[i-k]==false){
            ans+=r;
            success.push_back(true);
         }
         else success.push_back(false);
         break;
      case 'p':
         if (i-k<0){
            ans+=s;
            success.push_back(true);
         }
         else if(t[i-k]!='p' || success[i-k]==false){
            ans+=s;
            success.push_back(true);
         }
         else success.push_back(false);
         break;
      }
   }
   cout << ans << endl;
}