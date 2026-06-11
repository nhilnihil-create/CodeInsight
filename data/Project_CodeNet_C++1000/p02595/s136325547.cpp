#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n,d,aux1,aux2,cnt=0; cin>>n>>d;
  while(n--){
    cin>>aux1>>aux2;
    if(sqrt(aux1*aux1+aux2*aux2)<=d)
      cnt++;
  }
  cout<<cnt;
  return 0;
}