#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  long long A=0,B=0,C=0;
  for(long long i=0;i<N;i++){
    long long H;
    cin >> H;
    if(B<H){
      A=max(A,C);
      C=0;
    }
    else{
      C++;
    }
    B=H;
  }
  cout << max(A,C) << endl;
}
