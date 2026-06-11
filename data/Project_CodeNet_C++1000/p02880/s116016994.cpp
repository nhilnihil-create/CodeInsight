#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  for(int a=1;a<=9;a++)for(int b=1;b<=9;b++){
    if(a*b == N){
      cout <<"Yes" <<endl;
      return 0;
    }
    else{
    }
  }
  cout<<"No"<<endl;
  return 0;
//このようにしてmain関数に対する返し値は一つなのでこのようにかける
}