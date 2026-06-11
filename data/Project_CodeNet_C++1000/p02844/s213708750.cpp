#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

string func(int a){
   string num;
   if(a<100)
      num+='0';
   else
      num+=to_string(a/100);
   if(a<10)
      num+='0';
   else
      num+=to_string(a/10%10);
   num+=to_string(a%10);
   return num;
}

int main(){
   int n;
   cin >> n;
   string s;
   cin >> s;
   int ans=0;
   for(int i=0;i<1000;i++){
      int ncnt=0;
      string now = func(i);
      // cout << now << endl;
      for( int j=0;j<s.size();j++){
         if(now[ncnt]==s[j])
            ncnt++;
         if(ncnt==3){
            ans++;
            break;
         }
      }
   }
   cout << ans << endl;
   return 0;
}