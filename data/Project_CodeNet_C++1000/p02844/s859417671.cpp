#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void){
   int n,ans=0;
   string s;
   cin >> n >> s;
   rep(i,10)rep(j,10)rep(k,10){
                int x=30001,y=30001,flag=0;
                rep(a,n){
                    if(s[a]==i+48){
                     x = a;
                    break;
                     }
                }
                rep(b,n){
                    if(s[b]==j+48&&x<b){
                        y = b;
                        break;
                    }
                }
                rep(c,n){
                    if(s[c]==k+48&&y<c) flag++;
                }
                if(flag) ans++; 
   }
   cout << ans << endl;
}