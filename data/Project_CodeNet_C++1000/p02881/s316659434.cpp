#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N;
  long long minC=N+1;
  for(int i=1;i<=sqrt(N);i++){
    if(N%i==0){
      long long C=i+N/i;
      minC=min(minC,C);
    }
  }
  cout << minC-2 << endl;
}
    