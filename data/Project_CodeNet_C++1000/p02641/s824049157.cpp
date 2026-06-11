#include <bits/stdc++.h>
using namespace std;
int main(){
  int X,N;
  cin >> X>>N;
  vector<bool>p(101,true);
  while(N-->0){int i; cin>>i; p[i]=false;}
  for(int i=0;i<=101;i++){
    if(p[X-i]){cout << X-i <<endl;return 0;}
    else if(p[X+i]){ cout << X+i<<endl; return 0;}
  }
}