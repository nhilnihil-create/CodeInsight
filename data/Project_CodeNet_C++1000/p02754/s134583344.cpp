#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,A,B;
  cin >> N >> A >> B;
  long long div = N / (A+B);
  long long par = N % (A+B);
  
  if(par >= A) cout << div*A + A << endl;
  else cout << div*A + par << endl;
}