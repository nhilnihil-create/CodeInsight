// author: vinoda

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0; i<n; ++i)
    cin>>v[i];

  vector<int> check(n, -1), dummy;
  int cur=0;
  while(check[cur] == -1){
    check[cur] = v[cur]-1;
    cur=check[cur];
    dummy.push_back(cur);
  }

  int l=1, j=cur;
  j=check[j];
  while(j != cur){
    j=check[j];
    ++l;
  }
  int rem=(k-dummy.size()+l)%l;
  if(k<=dummy.size())  cout<<1+dummy[k-1]<<endl;
  else{
    while(rem){
      cur=check[cur];
      --rem;
    }
    cout<<1+cur<<endl;
  }
}
