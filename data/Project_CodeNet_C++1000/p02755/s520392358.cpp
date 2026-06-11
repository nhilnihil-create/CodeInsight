#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  for (int i=1; i<20000; i++){
    int x,y;
    x = i*0.08;
    y = i*0.1;
    if (x==a && y==b){
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}