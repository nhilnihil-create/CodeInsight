#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,A,B;
  cin>>N>>A>>B;
  if((B-A)%2==0)
    cout<<(B-A)/2<<endl;
  else if(A+B-1<N*2-(A+B)+1)
    cout<<(B+A-1)/2<<endl;
  else
    cout<<(N*2-(A+B)+1)/2<<endl;
}