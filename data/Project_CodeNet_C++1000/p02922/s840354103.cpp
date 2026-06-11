#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=0,b=0;
  cin>>a>>b;
  int count=0;
  int poket=1;
  while(poket<b){
    poket--;
    poket+=a;
    count++;
  }
  cout<<count<<endl;
}
