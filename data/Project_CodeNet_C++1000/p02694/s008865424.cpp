#include<iostream>
using namespace std;
int main(){
 long int x,y=100,count=1;
  
  cin>>x;
  while(count){
   
    y=y/100+y;
    if(y>=x){
      cout<<count;
      break;
    }
    count++;
  }
  return 0;
}
                                                                                           