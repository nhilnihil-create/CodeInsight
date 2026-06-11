#include <bits/stdc++.h>
using namespace std;

int N;long M;

long gojohou(long a,long b) {
  long _a=max(a,b);long _b=min(a,b);
  if (_a%_b==0) return _b;
  else return gojohou(_b,_a%_b);
}

long ruijo(long a){
  if (a%2L!=0) return 0;
  else {
    return 1L+ruijo(a/2);
  }
}

int main() {
  cin >> N >> M;vector<long> A(N,0L);bool kigu=true;
  for (int i=0;i<N;i++) {
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  long koubaisuu=A.at(0);
  for (int i=1;i<N;i++) {
    if (koubaisuu>2*M || ruijo(A.at(i-1))!=ruijo(A.at(i))) {
      koubaisuu=20000000005L;
      break;
    }
    if (A.at(i)!=A.at(i-1)) {
      long kouyakusuu=gojohou(koubaisuu,A.at(i));
      koubaisuu=(koubaisuu*A.at(i))/kouyakusuu;
    }
  }
  if (koubaisuu<=2*M && kigu) cout << (M+koubaisuu/2)/koubaisuu << endl;
  else cout << 0 << endl;
}