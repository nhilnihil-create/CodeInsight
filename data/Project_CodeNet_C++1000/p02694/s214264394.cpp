#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int x; cin>>x;
  int money=100,count=0;
  while(x>money){
    money+=money/100;
    count++;
  }
  cout<<count<<endl;
}