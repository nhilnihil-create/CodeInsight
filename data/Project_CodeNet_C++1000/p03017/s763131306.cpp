#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   ll n, a, b, c, d;   cin >> n >> a >> b >> c >> d;
   string s;    cin >> s;
   string ans="Yes";
    s = '#' + s + '#';
   if(c<d){
       for(ll i=b+1; i<d; i++){
           if(s.at(i)=='.' || s.at(i+1)=='.') continue;
           ans = "No"; 
       }
       for(ll i=a+1; i<c; i++){
           if(s.at(i)=='.' || s.at(i+1)=='.') continue;
           ans = "No"; 
       }
   }else{
       bool f = false;
       for(ll i=b; i<=d; i++){
           if(s.at(i-1)=='#' || s.at(i)=='#' || s.at(i+1)=='#') continue;
            f = true;
       }
       if(!f) ans = "No";

   }

   cout << ans << endl;
}