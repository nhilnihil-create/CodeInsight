#include<iostream>
using namespace std;

const int coins[] = {500, 100, 50, 10, 5, 1};
int main(){
  int m;
  while(cin >> m){
    if(m==0)break;

    m = 1000 - m;
    int res = 0;
    for(int i=0;i<6;i++){
      while(m >= coins[i]){
	res++;
	m -= coins[i];
      }
    }
    cout << res << endl;
  } 
}