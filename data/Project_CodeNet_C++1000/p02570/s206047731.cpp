
// Problem : A - Don't be late
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std ;

#define int  int64_t
#define all(a) (a).begin(), (a).end()

int32_t main(){ 
   ios::sync_with_stdio(false) ; 
   cin.tie(0) ;
   double d , t , s  ; 
   cin >> d >> t >> s ;
   double tm = d / s ;
   if(tm<=t){
      cout << "Yes" ; 
   }else{
      cout << "No";
   }
   cout << "\n" ; 
   
	return 0 ;
}