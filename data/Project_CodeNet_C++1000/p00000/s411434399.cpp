#include<iostream>
#define REP(i) for((i)=1;(i)<10;(i)++)
using namespace std;

int main(void){
  int i,j;
  REP(i){REP(j){
      cout<<i<<"x"<<j<<"="<<i*j<<endl;
    }
  }
  return 0;
}