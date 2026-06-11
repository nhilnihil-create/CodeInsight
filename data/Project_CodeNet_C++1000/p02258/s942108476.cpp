#include <iostream>
using namespace std;

int main(){

  int n;
  cin >> n;

  int r,minr;
  cin >> minr;

  int max= -999999999;

  for(int i=1;i<n;i++){
    cin >> r;
    if(max<r-minr)max=r-minr;
    if(minr>r)minr=r;
  }
  
  cout << max << endl;

}