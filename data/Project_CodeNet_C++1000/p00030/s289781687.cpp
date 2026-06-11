#include<iostream>
using namespace std;
int sum,s,ans;
int sbsum(int i,int s,int num){
  if(s == sum && num == 0)
    {ans++; return 0;}
  if(i == 10)
    return 0;
  if(num == -1)
    return 0;
  sbsum(i+1,s,num);
  sbsum(i+1,s+i,num-1);
}

int main(){
  int num;
  while(cin >> num >> sum && !(num == 0 && sum == 0)){ 
    ans=0;
    sbsum(0,0,num);
    cout << ans << endl;
  }
}