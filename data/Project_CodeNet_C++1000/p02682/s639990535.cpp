#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int   N = 0 ,A, B, C, K;
	string S;
	cin >> A >> B >> C >> K;
  
  if (K <= A) cout << K << endl;
  else if (K <= A + B) cout << A <<endl;
  else cout << 2*A + B -K << endl;
}
