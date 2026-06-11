#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D;cin >> A >> B >> C >> D;
  int Tak = (C-1) / B + 1,Aok = (A-1) / D + 1;
  if(Tak<=Aok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}