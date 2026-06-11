#include<iostream>
using namespace std;
int main(){
  int n;
  int H[251];

  cin >> n;
  for(int i=1;i<n+1;++i){
    cin >> H[i];
  }
  for(int i=1;i<n+1;++i){
    if(i==1){
      cout << "node " << i << ": key = " << H[i] <<", left key = "<< H[i*2]<<", right key = "<< H[i*2+1]<<", "<<endl;
    }
    else if(i<n/2){
      cout<< "node " << i << ": key = " << H[i] <<", parent key = "<< H[i/2]<<", left key = "<< H[i*2]<<", right key = "<<H[i*2+1]<<", "<<endl;;
    }
    else if(n%i==0 && n/i ==2){
      cout<< "node " << i << ": key = " << H[i] <<", parent key = "<< H[i/2]<<", left key = "<< H[i*2]<<", "<<endl;;
    }
     else if(n%i==1&& n/i ==2){
      cout<< "node " << i << ": key = " << H[i] <<", parent key = "<< H[i/2]<<", left key = "<< H[i*2]<<", right key = "<<H[i*2+1]<<", "<<endl;;
    }
    else{cout<< "node " << i << ": key = " << H[i] <<", parent key = "<< H[i/2]<<", "<<endl;
  
    }
  }
  return 0;
}