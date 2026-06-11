#include<bits/stdc++.h>
using namespace std;
  
int main(){
  long long A,B,N;
  cin >> A >> B >> N;
  if(B-1<=N){
    cout << A*(B-1)/B << endl;
  }
  else{
    cout << A*N/B << endl;
  }
}