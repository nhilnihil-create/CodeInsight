#include<iostream>
using namespace std;
int main()
{
 
  int k,a,b,i;
  cin>>k>>a>>b;
  
  for(i=a;i<b+1;i++){
    if(i%k==0){
      printf("OK\n");
      return 0;
    }
  }
  printf("NG\n");
  
  return 0;
}
