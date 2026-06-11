#include<iostream>
#include<string.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  bool card[52];
  for(int t=0;t<52;t++){
    card[t] = false;
  }

  char c;
  int x;
  for(int i=0;i<n;i++){
    cin >> c >> x;
    int j;
    if(strcmp(&c,"S")==0) j=0;
    else if(strcmp(&c,"H")==0) j=1;
    else if(strcmp(&c,"C")==0) j=2;
    else j=3;
    card[j*13+x-1] = true;
  }

  for(int s=0;s<52;s++){
    if(card[s] == false){
      switch(s/13){
        case 0:
          cout << "S " << s+1 << endl;
          break;
        case 1:
          cout << "H " << s%13+1 << endl;
          break;
        case 2:
          cout << "C " << s%13+1 << endl;
          break;
        case 3:
          cout << "D " << s%13+1 << endl;
          break;
        default:
          break;
      }
    }
  }
  return 0;
}