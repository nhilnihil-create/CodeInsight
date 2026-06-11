#include<bits/stdc++.h>
using namespace std;
int main(){long long n,i,s=0,k=0,a,b,p;
cin>>n;
if(n==1||n==2)
cout<<0;
else{
    if(n%2==0){
        for(i=1;i<(n/2);i++){
            s++;
        }cout<<s;}
        else{
            for(i=1;i<(n/2)+1;i++){
            s++;
        }cout<<s;
        }
    
}
  return 0;
}
