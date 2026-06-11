#include<iostream>

using namespace std;

int sum(int n){
  return n*(n+1)/2;
}

int main(void){

  int n;
  while(cin >> n,n){
    int cnt = 0;

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
	if(sum(j)-sum(i)==n)cnt++;
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}