#include <iostream>
using namespace std;
 
int main() {
  int x,y,s,i,j,sum;
  while(1){
    int max=0;
    cin>>x;
    cin>>y;
    cin>>s;
    if (x==0) break;
    for (i=1;i<s;i++){
      for (j=1;j<=s-i;j++){
    if (i*(100+x)/100+j*(100+x)/100==s){
      sum=i*(100+y)/100+j*(100+y)/100;
      if (max<sum) max=sum;
    }
      }
    }
    cout<<max<<endl;
  }
}