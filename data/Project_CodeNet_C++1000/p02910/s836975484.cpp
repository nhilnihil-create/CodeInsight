#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main(){
   string s;
   cin >> s;
   bool ok=true;
   rep(i,s.length()){
      if((1+i)%2) {
         if(s[i]== 'L') ok = false;
      }
      else{
         if(s[i] ==  'R') ok =false;
      }
   }
   if(ok)cout << "Yes" << endl;
   else cout << "No" << endl;
   return 0;
}
