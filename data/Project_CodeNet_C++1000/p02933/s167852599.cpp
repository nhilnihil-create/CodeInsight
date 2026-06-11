#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main(){
   int a;
   cin >> a;
   string s;
   cin >> s;
   if(a>=3200){
      cout << s << endl;
   }else cout << "red" << endl;
   return 0;
}