#include<bits/stdc++.h>
using namespace std;
int main(){
  long int h,n;
  cin>>h>>n;
  int v[n];
  for(int i=0;i<n;++i) cin >>v[i];
  int sum=0;
  for(int i=0;i<n;i++) sum+=v[i];
  if(sum>=h) cout << "Yes"<<endl;
  else cout <<"No"<<endl;
}
