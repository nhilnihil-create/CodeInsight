#include <bits/stdc++.h>

using namespace std;
int main(){
  long long a,b,i=1,num=0;
  cin>>a>>b;
  if(a<b)swap(a,b);
  while(num<a*b){
    num=a*i;
    if(num%b==0){
      cout<<num;
      break;
    }
    i++;
  }

  return 0;
}
