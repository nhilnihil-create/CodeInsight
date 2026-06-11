#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int H,W,N;cin>>H>>W>>N;
  int MAX=max(H,W);
  int V=N%MAX==0?N/MAX:N/MAX+1;
  cout<<V<<endl;
}
