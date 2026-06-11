#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
 ll n; cin >> n;
 string s; cin >> s;
 ll rcnt=0,gcnt=0,bcnt=0;
 rep(i,n){
   if(s[i]=='R')rcnt++; else if(s[i]=='G')gcnt++; else bcnt++;
 }
 ll ad=rcnt*gcnt*bcnt;
 ll cnt=0;
 for(int i=1;i<2005;i++){
   for(int j=0;j+2*i<n;j++){
     if(s[j]!=s[j+i] && s[j]!=s[j+2*i] && s[j+i]!=s[j+2*i])cnt++;
   }
 }
 cout << ad-cnt << endl;


}
