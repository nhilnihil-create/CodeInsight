#include <bits/stdc++.h>
using namespace std;

int main(){

  int e, cpy;

  while(cin >> e && e){

    int m = INT_MAX;

    for(int i = 0; i*i <= e; i++){
      for(int j = 0; j*j*j <= e; j++){
	cpy = e - i*i - j*j*j;
	if(e == i*i + j*j*j + cpy && cpy >= 0){
	    m = min(m,i+j+cpy);
	}
      }
    }
    cout << m << endl;

  }

 
}