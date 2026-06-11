#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e;
  cin>>a>>b;
  e=0;
  for(int i=22;i<=b;i++){
    c=i/10;
    d=i-c*10;
    if((c>=2)&&(d>=2)){
      if(c*d<=a){
        e++;
      }
    }
  }
  cout<<e<<endl;
}