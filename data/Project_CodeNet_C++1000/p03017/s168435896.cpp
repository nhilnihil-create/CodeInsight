#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main(){
   int n,a,b,c,d;
   cin >> n >> a >> b >> c >> d;
   string s; cin >> s;
   if(c<d){
      for(int i=a;i<d-1;i++){
         if(s[i]=='#'&&s[i+1]=='#'){
            cout << "No" << endl;
            return 0;
         }
      }
      cout << "Yes" << endl;
   }else{
      for(int i = b-2;i<d-1;i++){
         if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
            cout << "Yes" << endl;
            return 0;
         }
      }
      cout << "No"<<endl;
   }
  
   return 0;
}