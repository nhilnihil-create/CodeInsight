#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int count=0;
  count+=min(9,N);
  if(N>=100) count+=min(900,N-99);
  if(N>=10000) count+=min(90000,N-9999);
  cout<<count<<endl;
}
