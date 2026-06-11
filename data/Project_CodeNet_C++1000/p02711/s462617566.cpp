#include <bits/stdc++.h>
using namespace std;
int main(){
  string n;
  cin>>n;
  int x=0;
  for(int i=0;i<n.size();i++){
    if(n.at(i)=='7'){
      x+=1;}
  }
  if(x>0){
   cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
}
     
 
