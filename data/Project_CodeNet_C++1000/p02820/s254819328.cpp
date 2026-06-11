#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long
#define PI 2 * acos(0.0)
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
using namespace std;
int main(){
   fast_io
   ll n,k;
   cin>>n>>k;
   ll r,s,p;
   cin>>r>>s>>p;
   ll ans = 0;
   string s1;
   cin>>s1;
    string g;
   for(ll i = 0;i<s1.length();i++){
       if(i < k){
          if(s1[i] == 'r'){
             ans+=p;
             g.push_back('p');
          }
          if(s1[i] == 'p'){
             ans +=s;
              g.push_back('s');
          }
          if(s1[i] == 's'){
             ans += r;
              g.push_back('r');
          }
       }
       else{
         if(s1[i] == 's'){
            if(g[i-k] == 'r'){
               if(s1[i+k] == 'p' && i+k < (s1.length())){
                  g.push_back('p');
               }
               else{
                  g.push_back('s');
               }
            }
            else{
               ans += r;
                g.push_back('r');
            }
         }
         if(s1[i] == 'p'){
            if(g[i-k] == 's'){
               if(s1[i+k] == 's' && i+k < (s1.length())){
                  g.push_back('p');
               }
               else{
                  g.push_back('r');
               }
            }
            else{
               ans += s;
                g.push_back('s');
            }
         }
         if(s1[i] == 'r'){
            if(g[i-k] == 'p'){
               if(s1[i+k] == 'p' && i+k < (s1.length())){
                  g.push_back('r');
               }
               else{
                  g.push_back('s');
               }
            }
            else{
               ans += p;
                g.push_back('p');
            }
         }
       }
   }
   cout<<ans<<endl;
   return 0;
}