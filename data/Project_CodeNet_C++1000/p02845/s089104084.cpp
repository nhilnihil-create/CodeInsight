#include <bits/stdc++.h>
using namespace std;

int main(){

  int N,A,flag;
  long long ans = 1;
  cin >> N;

  int lis[3] = {0,0,0};

  for (int i = 0 ; i < N ; i++){

    cin >> A;

    flag = 0;

    for (int j = 0 ; j < 3 ; j++){

      if (lis[j] == A){

	if (flag == 0){
	  lis[j] += 1;
	}

	flag += 1;

      }
    }

    ans *= flag;
    ans %= 1000000007;

  }

  cout << ans << endl;

  return 0;

}