#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin>>X;
  int a=0,b=0;//a500 b5  
    
    a+=X/500;
   b+=(X-a*500)/5;
  cout<<1000*a+5*b<<endl;
}
