#include <bits/stdc++.h>
using namespace std;

int main(){

  while(1){

    int n, m, flower[100], tarou[100], cnt = 0, fsum = 0, tsum = 0, tchange, fchange;
    int ff, tt;
    int  fma = 99999, tma = 99999;

    cin >> n >> m;
    if(n == 0 && m == 0) break;

    for(int i = 0; i < n; i++){
      cin >> tarou[i];
      tsum+=tarou[i];
    }

    for(int i = 0; i < m; i++){
      cin >> flower[i];
      fsum+=flower[i];
    }

    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
	tt = tsum - tarou[j] + flower[i];
	ff = fsum - flower[i] + tarou[j];
	//cout << tt << " " << ff << endl;
	if(tt == ff){
	  cnt = 1;
	  tchange = tarou[j];
	  fchange = flower[i];
	  if(tma + fma > tchange + fchange){
	    //  cout << 1111111;
	    tma = tarou[j];
	    fma = flower[i];
	  }
	}
      }
    }
    if(cnt == 1)     cout << tma << " " << fma << endl;
    else cout << -1 << endl;


  }

  return 0;
}