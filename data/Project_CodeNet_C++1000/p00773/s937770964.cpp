#include <bits/stdc++.h>
using namespace std;

int main(){

  int x, y, p;

  while(cin >> x >> y >> p && (x || y || p)){

    int max = INT_MIN;
    //    int maxi, maxj;

    for(int i = 1; i <= 1000; i++){ 
      for(int j = i; j <= 1000; j++){
	if((i * (100 + x) / 100) + (j * (100 + x) / 100) == p){
	  if(max < (i * (100 + y) / 100) + (j * (100 + y) / 100)){
	    max = (i * (100 + y) / 100) + (j * (100 + y) / 100);
	    //	    maxi = i;
	    //maxj = j;
	  }
	}
      }
    }
    cout << max << endl;
    // cout << maxi << " " << maxj << endl;


  }




  return 0;
}