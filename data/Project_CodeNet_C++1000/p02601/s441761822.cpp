#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  
  int Cmax = C;
  
  if(B>A){
    for(int i=0; i<K ;i++){
    Cmax = Cmax*2;
    }
    if(Cmax>B){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else{
    int Bmax = B;
    for(int i=0; i<K ;i++){
      Bmax = Bmax*2;
      if(Bmax>A){
        for(int j=0; j<K-i-1 ;j++){
          Cmax = Cmax*2;
        }
        if(Cmax>Bmax){
        cout << "Yes" << endl;
        }
        else{
        cout << "No" << endl;
        }
        break;
      }
    }
    
    if(Bmax<=A){
      cout << "No" << endl;
    }
  }
  
}

