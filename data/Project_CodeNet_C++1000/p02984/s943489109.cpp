#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,i,k,s=0;
  cin>>n;
  vector<int> a(n);
  for(i=0;i<n;i++){
    cin>>a.at(i);
    k=a.at(i);
    if(i%2==1) k*=-1;
    s+=k;
  }
  cout<<s<<' ';
  for(i=1;i<n;i++){
    s=(s-a.at(i-1))*(-1)+a.at(i-1);
    cout<<s;
    if(i<n-1) cout<<' ';
    else cout<<endl;
  }
}