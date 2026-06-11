#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int TH,TA,AH,AA;
  cin >> TH >> TA >> AH >> AA;
  while(true){
    AH-=TA;
    if(AH<=0){
      cout << "Yes" << endl;
      return 0;
    }
    TH-=AA;
    if(TH<=0){
      cout << "No" << endl;
      return 0;
    }
  }
}