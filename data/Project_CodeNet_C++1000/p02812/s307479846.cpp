#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   string s;
   cin >> n >> s;
   int count=0;
   for(int i=0;i<s.length()-2;i++){
      if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
         count++;
      }
   }

   cout << count << endl;
   return 0;  
}