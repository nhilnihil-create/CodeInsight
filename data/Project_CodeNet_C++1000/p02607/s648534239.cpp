#include<iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int arr[N];
  int cntr = 0;
  for(int i = 0; i < N; i++){
  	cin >> arr[i];
    if((i+1) % 2 == 1 && arr[i] % 2 == 1)
      cntr++;
  }
  cout << cntr;
}