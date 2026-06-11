#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,rem,a[4],i=0,d,ans=0;
 cin>>n;
 while(n>0){
     rem=n%10;
    
     a[i]=rem;
      n=n/10;
      i++;
 }
    
 d=a[0];
for(i=1;i<4;i++){
    if(a[i]==d){
        ans++;
        break;
    }
    d=a[i];
}
if(ans==1)
cout<<"Bad";
else
cout<<"Good";
  }