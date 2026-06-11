#include<iostream>
using namespace std;

int main() {
  long T1, T2, A1, A2, B1, B2; cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  if (T1*A1+T2*A2==T1*B1+T2*B2) { cout << "infinity" << endl; return 0; }
  long M1 = T1*A1-T1*B1, M2=T2*A2-T2*B2;
  if (M1+M2<0) {M1 = -M1; M2=-M2;}
  if (M2 > 0) cout<<(max(0L, (M2-1)/(M1+M2)-1) + max(0L, M2/(M1+M2)))<<endl;
  else cout<<(max(0L, (M2)/(M1+M2)-1) + max(0L, (M2+1)/(M1+M2)-1))<<endl;
}