#include<iostream>
using namespace std;

int main(){
  int N; cin >> N;
  
  int page = N / 2;
  
  if(N % 2 == 0){
    cout << page << endl;
  }
  
  if(N % 2 == 1){
    cout << page + 1 << endl;
  }
  
}