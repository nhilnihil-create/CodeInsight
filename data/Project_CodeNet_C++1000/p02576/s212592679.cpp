#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, X, T;
  	cin >> N >> X >> T;
  	int a = N / X;
 if(N % X != 0) T *= a + 1;
  if(N % X == 0) T *= a;
  cout << T << endl;
}