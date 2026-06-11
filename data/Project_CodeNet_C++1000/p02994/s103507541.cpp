#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,L;cin>>N>>L;

  int sum = N*L + N*(N-1)/2;

  if(L>=0){
    cout<<sum-L<<endl;
  }else if(L<0 && N>(-L)){
    cout<<sum<<endl;
  }else if(L<0 && N<=(-L)){
    cout<<(sum-(L+N-1))<<endl;
  }
}