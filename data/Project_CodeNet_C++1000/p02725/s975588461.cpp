#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,n;
  cin>>k>>n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a.at(i);
  }
  int d=-1;
  for(int i=1; i<n; i++){
    d=max(d,a.at(i)-a.at(i-1));
  }
  if(a.at(0)+k-a.at(n-1)>d) d=a.at(0)+k-a.at(n-1);
  cout<<k-d<<endl;
}
