#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
   int k;
   cin>>k;
   if(k%2==0 || k%5==0){
    cout<<-1<<endl;
       return 0;
   }
   int p=7%k,ans=1;
   while(p){
       p=p*10+7;
       p=p%k;
       ans++;
   }
   cout<<ans<<endl;
}