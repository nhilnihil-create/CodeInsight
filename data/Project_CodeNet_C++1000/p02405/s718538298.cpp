#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
  int H, W;


  while(cin>>H>>W && H!=0 && W!=0){
    for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
        if((i%2==0 && j%2==0)||(i%2!=0 && j%2!=0)){
          cout<<"#";
        }else{
          cout<<".";
        }

        }
        cout<<endl;
      }
      cout<<endl;
    }
}