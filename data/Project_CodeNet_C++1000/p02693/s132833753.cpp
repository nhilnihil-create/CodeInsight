#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  
  int largest = ( B/K ) * K;
  
  if(A <= largest){
	cout << "OK" << endl;
  }else{
	cout << "NG" << endl;
  }
}