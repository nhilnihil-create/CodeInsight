#include "algorithm"
#include "iostream"
#include "cmath"
#include "string"
#include "map"
using namespace std;


int main(){
  while(true){
    int n,p;
    cin >> n >> p;
    if(!n&&!p)break;
    int a[n]={0};
    int wan=p,i;
    for(i=1;i<1000001;++i){
      if(wan==0){
        wan+=a[i%n];
        a[i%n]=0;
      }else {
        --wan;
        ++a[i%n];
        if(a[i%n]==p)break;
      }
    }
    cout << (i-1)%n <<endl;
  }
  return 0;
}