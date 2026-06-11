#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n;

  while(cin>>n&&n!=0){
    int min=n+1;
    int count=0;
    for(int i=min;i<=2*n;i++){
      if(i==2||i==3) count++;
      else if(i%2!=0){
        for(int j=2;j<=(int)(sqrt(i));j++){
          if(i%j==0) break;
          if(j==(int)(sqrt(i))){
            count++;
          }
        }
      }
    }
    cout << count << endl;
  }

  return 0;
}