/*修正*/
#include<bits/stdc++.h>
using namespace std;
void part(){
  int x,n,p;
  cin>>x>>n;
  unordered_map<int,int> unmp;
  while(n--){
    cin>>p;
    ++unmp[p];
  }
  for(int i=0;i<=x;i++){
    for(auto j:{-1,1}){
      int a=x+i*j;
      if(unmp[a]==0){
        cout<<a;
        return;
      }
    }
  }
}
int main(void){
  int num=1;
  while(num--){
    part();
  }
  return 0;
}