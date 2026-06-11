#include<bits/stdc++.h>
using namespace std;

int main(){
  int x; cin>>x;
  int happy=0;
  happy+=x/500*1000;
  x-=x/500*500;
  happy+=x/5*5;
  cout<<happy<<endl;
}