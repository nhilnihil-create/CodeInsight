#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int H1, H2;
  int M1, M2;
  int K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  int A = H1*60+M1;
  int B = H2*60+M2-K;
  if(B-A<0){
    cout << "0" << endl;
    return 0;
  }
  cout << B-A << endl;
  return 0;
}