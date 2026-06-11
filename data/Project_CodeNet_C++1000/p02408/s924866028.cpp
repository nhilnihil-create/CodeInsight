#include <iostream>
using namespace std;
void lackcardp(int num,int a[20],int count){
  int k = 0;
  for(int i =1;i < 14;i++){
    for(int j = 0;j <count;j++){
      if(a[j] == i){
        k = 1;
        break;
      }
    }
    if(k == 0){
      if(num == 0){
        cout << "S "<< i << endl;
      }else if(num == 1){
        cout << "H "<< i << endl;
      }else if(num == 2){
        cout << "C "<< i << endl;
      }else if(num == 3){
        cout << "D "<< i << endl;
      }
    }
    k = 0;
  }
}

int main(){
  int n;
  cin >> n;
  std::string cirast;
  int cnum;
  int ccount=0;
  int hcount=0;
  int dcount=0;
  int scount=0;
  int sp[20]={0};
  int he[20]={0};
  int cl[20]={0};
  int di[20]={0};
  for(int i = 0;i < n;i++ ){
    cin >> cirast >> cnum;
    if( cirast == "S"){
      sp[scount] = cnum;
      scount += 1;
    }else if( cirast == "H"){
      he[hcount] = cnum;
      hcount += 1;
    }else if(cirast == "C"){
      cl[ccount] = cnum;
      ccount += 1;
    }else if(cirast == "D"){
      di[dcount] = cnum;
      dcount += 1;
    }
  }
  lackcardp(0,sp,scount);
  lackcardp(1,he,hcount);
  lackcardp(2,cl,ccount);
  lackcardp(3,di,dcount);
}