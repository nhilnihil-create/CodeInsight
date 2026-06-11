#include<iostream>
using namespace std;

int main(){
  int K;
  cin >> K;
  int sum=0;
  
  for(int a=1;a<=K;a++){
    for(int b=1;b<=K;b++){
      for(int c=1;c<=K;c++){
        for(int d=(min(min(a,b),c));d>=1;d--){
          if(a%d==0 && b%d==0 && c%d==0){
            sum+=d;
            break;
          }
        }
      }
    }
  }
  
  cout << sum << endl;
}
