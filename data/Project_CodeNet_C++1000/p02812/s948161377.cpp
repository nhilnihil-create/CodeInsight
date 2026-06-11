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
   int n ; cin >> n ;
   map<string , int> mp;
   string s ; cin >> s ;
   for(int i = 0 ; i < n-2 ; i++){
   	 string t ="";
   	 t+=s[i];
   	 t+=s[i+1];
   	 t+=s[i+2];
   	 mp[t]++;
   }
   cout << mp["ABC"] << endl;
   
   
}
