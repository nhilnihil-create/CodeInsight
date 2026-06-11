#include<iostream>
using namespace std;
int main(){
  int h,w;
  while(cin >> h >> w && h||w){
    for(int j=0;j<w;j++) cout << "#";
    cout << endl;
    for(int i=1;i<h-1;i++){
      cout << "#";
      for(int j=1;j<w-1;j++) cout << ".";
      cout << "#" << endl;
    }
    for(int j=0;j<w;j++) cout << "#";
    cout << endl << endl;
  }
}
