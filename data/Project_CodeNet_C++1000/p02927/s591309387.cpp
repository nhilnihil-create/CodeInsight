#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int M,D;
  cin >> M >> D;
  int count = 0;
  for(int i = 1; i <= M; i++){
  	for(int j = 1; j <= D; j++){
    	int d_one = j % 10;
      	int d_ten = (j - d_one) / 10;
      	if(d_one >= 2 && d_ten >= 2 && i == d_one * d_ten){
        	count++;
        }
    }
  }
  cout << count << endl;
}