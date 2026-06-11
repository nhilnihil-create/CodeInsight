#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,X;cin>>K>>X;
  int left=max(-100000,X-K+1);
  int right=min(100000,X+K-1);
  cout<<left;
  for(int i=left+1;i<=right;i++) cout<<" "<<i;
  cout<<endl;
}
  
