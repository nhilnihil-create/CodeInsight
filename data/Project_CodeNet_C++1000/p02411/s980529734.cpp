#include <iostream>
using namespace std;

int main(){
  int m, f, r;
  char grade;
  while(true){
    cin >> m >> f >> r;
    if(m==-1 & f==-1& r==-1) break;
    if(m==-1 | f==-1) grade='F';
    else  if(m+f>=80) grade='A';
    else if(m+f<80&m+f>=65) grade='B';
    else if(m+f<65&m+f>=50) grade='C';
    else if(m+f<50&m+f>=30){
      if(r>=50) grade='C';
      else grade='D';
    }
    else grade='F';
    cout << grade << endl;
  }
}

