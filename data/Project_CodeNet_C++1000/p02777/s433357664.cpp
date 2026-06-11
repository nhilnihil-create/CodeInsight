#include<bits/stdc++.h>
using namespace std;
int main(){
int x,y;
string  a,b,u;
cin>>a>>b;
cin>>x>>y;
 cin>>u;

  if(u==a){
    x--;
  }
  else if(u==b){
    y--;
  }
    cout<<x<<" "<<y;
}
