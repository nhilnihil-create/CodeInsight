#include<bits/stdc++.h>
using namespace std;

int main(){
  long long A;
  double B;
  cin >> A >> B;
  int C=100*B+0.00001;
  cout <<(long long)A*C/100 << endl;
}
  