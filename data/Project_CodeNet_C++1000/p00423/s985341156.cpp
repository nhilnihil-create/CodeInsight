#include<iostream>
using namespace std;
int main(){
  int n;
  int a,b;
  int ak,bk;
  while(1){
    cin >> n;
    ak=0;
    bk=0;
    if(n==0) break;
    for(int i=0;i<n;i++){
      cin >> a >> b;
      if(a<b) bk+=a+b;
      else if(a>b) ak+=a+b;
      else if(b==a){
	ak+=a;
	bk+=b;
      }
    }
    cout <<ak<<" "<<bk<<endl;
  }
}