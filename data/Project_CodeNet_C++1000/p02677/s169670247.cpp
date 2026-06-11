#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,H,M;
  cin >> A >> B >> H >> M;
  double P=acos(-1)*(60*H+M)/360;
  double Q=acos(-1)*M/30;
  cout << fixed << setprecision(10) << sqrt(A*A+B*B-2*A*B*cos(P-Q)) << endl;
}
  