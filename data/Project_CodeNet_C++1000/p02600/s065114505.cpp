#include<iostream>

using namespace std;

int main(){
  int a;
  cin >> a;
  if(400<=a && a<=599){
    cout << 8 << endl;
  }else if(600<=a && a<=799){
    cout << 7 << endl;
  }else if(800<=a && a<=999){
    cout << 6 << endl;
  }else if(1000<=a && a<=1199){
    cout << 5 << endl;
  }else if(1200<=a && a<=1399){
    cout << 4 << endl;
  }else if(1400<=a && a<=1599){
    cout << 3 << endl;
  }else if(1600<=a && a<=1799){
    cout << 2 << endl;
  }else if(1800<=a && a<=1999){
    cout << 1 << endl;
  }
}