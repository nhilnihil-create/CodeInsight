#include <bits/stdc++.h>
using namespace std;

int main() {
  long N; cin>>N;
  long S;
  for(int i=1;i<=sqrt(N);i++){
    if(N%i==0) S=i;
  }
  long T=N/S;
  cout<<S+T-2<<endl;
}