#include <iostream>

using namespace std;

int main(){
  while(true){
  int m,nmin,nmax;
  cin >> m >> nmin >> nmax;
  if(m==0)break;
  int list[m];
  for(int i=0;i<m;i++){
    cin >> list[i];
  }
  int gap=0,c;
  for(int i=nmin-1;i<nmax;i++){
    if(list[i]-list[i+1]>=gap){
      gap=list[i]-list[i+1];
      c=i+1;
    }
  }
  cout << c << endl;
  }
  return 0;
}