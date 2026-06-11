#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b,c,d,max,min;
  cin>>a>>b;

  if(b==0){cout<<a<<endl;}
  else{
    
    vector<int> vec(b);
    
  for(int i=0;i<b;i++){
  cin>>vec.at(i);
  }
   
  for(int i=a;i<=a+100;i++){
    c=0;
    for(int j=0;j<b;j++)
    {if(vec.at(j)==i){c=1;}}
    if(c==0){max=i;
           break;}
  }
    
    for(int i=a;i>=a-100;i--){
    d=0;
    for(int j=0;j<b;j++)
    {if(vec.at(j)==i){d=1;}}
    if(d==0){min=i;
            break;}
  }
   
    if((max-a)<(a-min)){cout<<max<<endl;}
  if((max-a)>=(a-min)){cout<<min<<endl;}
 
  }
  
 
}
