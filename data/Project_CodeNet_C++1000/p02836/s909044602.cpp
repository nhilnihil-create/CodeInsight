/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with(false); cin.tie(0);cout.tie(0);
const int MOD = 1000000007;
#define PI = acos(-1)
using namespace std ;
int a[106];
int main(){
     string s ; cin >> s ;
     int x = s.size();
     int cnt = 0 ;
     for(int i = 0 ; i < x/2 ; i++){
     	  if(s[i] != s[x-i-1])
     	     cnt++;
	 }
	 cout << cnt ;
}

