#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
using namespace std;


int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);

   string s,hitachi="";
   cin >> s;
   bool ok=false;
   rep(j,0,5){
     hitachi+="hi";
     if(s==hitachi) ok=true;
   }
   if(ok)cout << "Yes" << endl;
   else cout << "No" << endl;
   
}

