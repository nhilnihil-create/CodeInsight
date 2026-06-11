#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,j=0;
  cin>>n;
  vector<int> p(n);
  for(int &i:p)
    cin>>i;
  for(int i=1;i<n-1;i++)
    if((p[i-1]<p[i] && p[i]<p[i+1])||(p[i-1]>p[i] && p[i]>p[i+1]))
      j++;
  cout<<j<<endl;
}