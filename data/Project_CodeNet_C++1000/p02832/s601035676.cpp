#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  int j=0,k=1;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a!=k)
      j++;
    else
      k++;
  }
  if(N==j)
    cout<<-1<<endl;
  else
    cout<<j<<endl;
}