#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long
#define PI 2 * acos(0.0)
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
using namespace std;
bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) 
{ 
       return (a.first > b.first); 
} 
int main(){
   fast_io
   string s;
   cin>>s;
   ll i = 0;
   ll j = s.length()-1;
   ll ans = 0;
   while(i <= j){
      if(s[i] != s[j]) ans++;
      j--;
      i++;
   }
   cout<<ans<<endl;
   return 0;
}