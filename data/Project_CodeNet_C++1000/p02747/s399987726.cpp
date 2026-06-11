#include<bits/stdc++.h>
using namespace std;
int main(){string s;
cin>>s;
long long n,i,m=0,p=0;
n=s.size();if((n%2)==1)
cout<<"No";
else{
for(i=0;i<n;i+=2){
  if(s[i]!='h'){
      m=1;break;
  }
}if(m==1)
cout<<"No";
else{
    for(i=1;i<n;i+=2){
        if(s[i]!='i'){
            p=1;break;
        }
    }if(p==1)
    cout<<"No";
    else
    cout<<"Yes";
}}
 
    return 0;
  
}
