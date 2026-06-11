#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> p(n);
  for(int i=0; i<n; i++){
    cin>>p[i];
  }
  int cnt=0;
  for(int i=0; i<n-2; i++){
    if(p[i+1]!=min({p[i],p[i+1],p[i+2]})&&p[i+1]!=max({p[i],p[i+1],p[i+2]})){
      cnt++;
    }
  }
  cout<<cnt<<endl;
}