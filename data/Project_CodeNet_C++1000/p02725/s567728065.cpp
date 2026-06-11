#include<iostream>
#include<string>
using namespace std;
int main(){
  int n, c, k = 0, s = 0;
  cin >> n >> c;
  int a[n], b[n];
  for(int i = 0; i < c; i++){
    cin >> a[i];
  }
  for(int i = 0; i < c; i++){
    if(i < c - 1){
	    b[i] = a[i + 1] - a[i];
          if(s < b[i]){
    	  s = b[i];
          }
    }
    if(i == c - 1){
      b[i] = (n + a[0]) - a[i];
      if(s < b[i]){
        s = b[i];
      }
    }
  }
  k = n - s;
  cout << k << "\n";
}