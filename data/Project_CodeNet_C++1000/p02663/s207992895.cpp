#include<bits/stdc++.h>
using namespace std;

int main(){
   int a,b,c,d,p;
   cin>>a>>b>>c>>d>>p;
   int t=d+(60-b);
   int y=(c-a-1)*60;
  t=t+y;
  t=t-p;
  cout<<t;
}
