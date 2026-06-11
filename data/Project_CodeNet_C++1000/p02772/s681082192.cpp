#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2)
 
int main() {
  int N;
  cin >> N;
  REP(i,N) {
    int A;
    cin >> A;
    if(A % 2 == 0 && A % 3 != 0 && A % 5 != 0) {
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
}