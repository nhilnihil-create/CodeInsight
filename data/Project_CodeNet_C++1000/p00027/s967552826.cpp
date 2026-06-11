#include<iostream>
using namespace std;
int month[12]={0,3,4,0,2,5,0,3,6,1,4,6};
int main(){
  int m,d;
  while(cin >>m>>d,m||d){
    switch((d+month[m-1])%7){
    case 1:
      cout <<"Thursday"<<endl;break;
    case 2:
      cout <<"Friday"<<endl;break;
    case 3:
      cout <<"Saturday"<<endl;break;
    case 4:
      cout <<"Sunday"<<endl;break;
    case 5:
      cout <<"Monday"<<endl;break;
    case 6:
      cout <<"Tuesday"<<endl;break;
    case 0:
      cout <<"Wednesday"<<endl;break;
    }
  }
  return 0;
}