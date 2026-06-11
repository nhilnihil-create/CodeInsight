#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll A;
  string B;
  cin >> A >> B;
  int C = (B[0]-'0')*100+(B[2]-'0')*10+(B[3]-'0');
  cout << ll(A*C/100) << endl;
}
