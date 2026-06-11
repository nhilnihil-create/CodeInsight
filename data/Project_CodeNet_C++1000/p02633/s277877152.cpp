#include<bits/stdc++.h>
using namespace std;
int main(){
  	int x;
  cin >> x;
  int k = 1;
  for(int i=1;i<=360;i++){
  	if((i * x )%360 == 0){
    	cout << i;
      return 0;
    }
  }
	return 0;
}