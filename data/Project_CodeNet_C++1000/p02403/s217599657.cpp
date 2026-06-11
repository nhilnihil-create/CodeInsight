#include <iostream>
using namespace std;
int main(){
int x,y;
  while(cin>>x>>y){
     if(x==0&&y==0)break;
          for(int k=1;k<=x;k++){
                       for(int j=1;j<=y;j++){
                               cout<<"#";
                         }    
                 cout<<endl;
           }
cout<<endl;
  }
}