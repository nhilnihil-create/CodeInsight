#include <bits/stdc++.h>
using namespace std;

int main(){
  string B;
  cin >> B;
  vector<char>A(22);
  A[1]='S';
  A[2]='A';
  A[3]='T';
  A[4]='F';
  A[5]='R';
  A[6]='I';
  A[7]='T';
  A[8]='H';
  A[9]='U';
  A[10]='W';
  A[11]='E';
  A[12]='D';
  A[13]='T';
  A[14]='U';
  A[15]='E';
  A[16]='M';
  A[17]='O';
  A[18]='N';
  A[19]='S';
  A[20]='U';
  A[21]='N';
  for(int i=1;i<20;i+=3){
    if(A[i]==B.at(0)){
      if(A[i+1]==B.at(1)){
        cout << (i+2)/3 << endl;
      }
    }
  }
}
