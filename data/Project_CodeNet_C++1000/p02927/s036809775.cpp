#include<bits/stdc++.h>
using namespace std;

int main(){
  int m,d;
  cin >> m >> d;
  
  int i,s;
  s=0;
  for(i=1;i<=d;i++){
    int t,o;
    o=i%10;
    t=i/10;
    if(t>=2&&o>=2&&t*o<=m){
      s++;
    }
  }
  
  cout << s << endl;
}