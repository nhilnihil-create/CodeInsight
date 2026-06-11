#include<bits/stdc++.h>
using namespace std;

int main(){
  int l , r , d;
  int count = 0;
  scanf("%d %d %d",&l,&r,&d);
  for(int i = l;i <= r;i++){
    if(i % d == 0)
      count++;
  }
  cout << count << "\n";
  return 0;
}
