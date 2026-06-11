#include <bits/stdc++.h>
using namespace std;
int main(){
 int a,b;
  cin>>a>>b;
  if(a==b){
  	for(int i=1;i<=a;i++){
    cout<<a;
    }
  }
  else if(a<b){
  for(int i=1;i<=b;i++){
  cout<<a;
  }
  }
  else{
  for(int i=1;i<=a;i++){
  cout<<b;
  }
  }
}
