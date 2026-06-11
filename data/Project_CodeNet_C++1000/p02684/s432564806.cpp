#include "bits/stdc++.h"
using namespace std;

void course0();

int main()
{
	int c = 0;
	if (c == 0) course0();
	getchar();
	getchar();
    return 0;
}

void course0()
{
  long long N, K;	
  cin >> N >> K;
  vector<int> A(N,0),junban(N,0);
  for (int i = 0; i<N; i++){
    int x=0;
    cin >> x;
    A.at(i) = x-1;
  }
  int jun = 1;
  int i = 0;
  while (K > 0){    
    if (junban.at(i) == 0){
      //cout << K << endl;
      junban.at(i) = jun;
      jun++;
      i = A.at(i);
      K--;
    }else{
      K = K % (jun - junban.at(i));
      break;
    }
  }
  while (K > 0) {
    i = A.at(i);
    K--;
  }
  cout << i+1 << endl;
  
}