#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    vector<ll> sum(500001);
    ll sumo=0;
    rep(i,500001){
        sumo+=i;
        sum.at(i)=sumo;
    }
   string s;
   cin >> s;
   int n=s.size();
   ll ans=0;
   ll cntl=0;
   ll cnts=0;
   int x=0;
   int y=0;
   rep(i,n){
       if(s.at(i)=='<'){
           if(cntl==0){
               x=0;
               y=0;
               cnts=0;
           }
           if(i==n-1){
               cntl++;
               ans+=cntl;
           }
           else if(i!=n-1 && s.at(i+1)=='>'){
               cntl++;
               x=cntl;
           }
           else if(cntl==0){
               x=0;
               y=0;
               cnts=0;
               cntl++;
               ans+=cntl;
           }
          
           else{
               cntl++;
               ans+=cntl;
           }

       }
       else if(s.at(i)=='>'){
           if(cnts==0){
               y=0;
               cntl=0;
           }
           if(i==n-1){
               cnts++;
               y=cnts;
               ans+=max(x,y);
               ans+=sum.at(cnts-1);
            }
           else if(i!=n-1 && s.at(i+1)=='<'){
               cnts++;
               y=cnts;
               ans+=max(x,y);
               ans+=sum.at(cnts-1);
           }
           else if(cnts==0){
               y=0;
               cntl=0;
               cnts++;
           }
           else{
               cnts++;
           }
       }
   }
   cout << ans << endl;
}
       