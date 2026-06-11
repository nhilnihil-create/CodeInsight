#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A;
  cin >> N;
  if(N%2==0){
    A=N/2;
  }
  else{
    A=(N+1)/2;
  }
  cout << fixed << setprecision(10) << (double)A/N << endl;
}
  