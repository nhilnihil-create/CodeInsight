#include "iostream"
using namespace std;
int main(){
  int a[3];
  int c[3];
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  int v=0;
  for(int i=0;i<3;i++){
    for(int j=i+1;j<3;j++){
      c[v]=a[i]+a[j];
      v+=1;



    }
  }
  int d=c[0];
  for(int i=1;i<3;i++){
    if(c[i]<d){
      d=c[i];
    }
  }
  cout<<d<<endl;

}
