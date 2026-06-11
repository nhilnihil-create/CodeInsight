#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long money,target,cnt;
  money=100;
  cin>>target;
  cnt=0;
  
  while(money<target){
    money=money+money/100;
    cnt++;
  }
  cout<<cnt;
}