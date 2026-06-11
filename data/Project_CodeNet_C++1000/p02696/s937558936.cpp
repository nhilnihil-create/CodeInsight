#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int A,B,N;
  cin>>A>>B>>N;
  int j=min(B-1,N);
  cout<<A*j/B-A*(j/B)<<endl;
}