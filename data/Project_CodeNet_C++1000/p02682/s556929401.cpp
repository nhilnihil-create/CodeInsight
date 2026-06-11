#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int   N = 0 ,A, B, C, K;
	string S;
	cin >> A >> B >> C >> K;
  
  for(long long int i=0; i < K ; i++){
  	if(i < A) N++;
    else if (i+1 > A + B) N--;
  }
  cout << N << endl;
}
