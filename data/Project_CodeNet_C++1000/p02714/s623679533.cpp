#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
 int main() {
   int n;
     string s;
       cin>>n>>s;
         vector<int> Rn(n),Gn(n),Bn(n);
           int tmp=0;
             rep(i,n){
                 if(s[i]=='R')tmp++;
                     Rn[i]=tmp;
                       }
                         tmp=0;
                           rep(i,n){
                               if(s[i]=='G')tmp++;
                                   Gn[i]=tmp;
                                     }
                                       tmp=0;
                                         rep(i,n){
                                             if(s[i]=='B')tmp++;
                                                 Bn[i]=tmp;
                                                   }
                                                     ll ans=0;
                                                       for(int i=0; i<n; i++){
                                                           for(int j=i+1; j<n; j++){
                                                                 if((s[i]=='R' && s[j]=='G') || (s[i]=='G' && s[j]=='R')){
                                                                         ans+=Bn[n-1]-Bn[j];
                                                                                 if(2*j-i<n && s[2*j-i]=='B'){
                                                                                           ans--;
                                                                                                   }
                                                                                                         }
                                                                                                               if((s[i]=='G' && s[j]=='B') || (s[i]=='B' && s[j]=='G')){
                                                                                                                       ans+=Rn[n-1]-Rn[j];
                                                                                                                               if(2*j-i<n && s[2*j-i]=='R'){
                                                                                                                                         ans--;
                                                                                                                                                 }
                                                                                                                                                       }
                                                                                                                                                             if((s[i]=='B' && s[j]=='R') || (s[i]=='R' && s[j]=='B')){
                                                                                                                                                                     ans+=Gn[n-1]-Gn[j];
                                                                                                                                                                             if(2*j-i<n && s[2*j-i]=='G'){
                                                                                                                                                                                       ans--;
                                                                                                                                                                                               }
                                                                                                                                                                                                     }
                                                                                                                                                                                                         }
                                                                                                                                                                                                           }
                                                                                                                                                                                                             cout<<ans<<endl;
                                                                                                                                                                                                             }