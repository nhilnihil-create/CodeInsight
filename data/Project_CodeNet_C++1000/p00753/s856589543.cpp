#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;

  while(cin >> n && n){

    int cnt = 0, judge = 0;

    if(n == 1 || n == 2) cout << 1 << endl;
    else {
      for(int i = n+1; i <= 2*n; i++){
	for(int j = 1; j <= sqrt(i); j++){
	  if(i % j == 0){
	    judge++;
	    //  cout << i << endl;;
	  }
	}
	//	cout << judge << endl;
	if(judge == 1){
	  //  cout << i << endl;
	  cnt++;
	  judge = 0;
	}else judge = 0;     
      }
      cout << cnt << endl;
    }


  }

  return 0;
}