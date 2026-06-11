#include <iostream>

using namespace std;


int main(){
 int N,M;
  cin >> N >>M;
  if(N%2==1){
   for(int i=1;i<=M;i++){
    cout << M+1-i<<" " <<M+i <<endl; 
   }
  }else{
    if(N%4==0){
      int l=N-1,h=N;
      for(int i=1;i<=M;i++){
        cout<< l<< " " <<h<<endl;
        l--;
        h++;
        if(i==N/4)
          h++;
        if(h>N)
          h%=N;
      }
    }else{
     int l=N-1,h=N;
      for(int i=1;i<=M;i++){
        cout<< l<< " " <<h<<endl;
        l--;
        h++;
        if(i==N/4)
          h++;
        if(h>N)
          h%=N;
      }
    } 
    
  }
 
  return 0;
}
