#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int P, Q, R;
  string S, T;
  cin >> P >> Q >> R;
  
  cout << min(P + Q , min(Q + R , R + P)) << endl;
}
