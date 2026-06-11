#include <bits/stdc++.h>
using namespace std;
int main() { 
  int n,l;
  cin>>n>>l;
  vector<int>b(n);
  int a=0;
  int c=0;
  for(int i=0;i<n;i++){
    b.at(i)=l+i;
    cin>>b.at(i);
    a+=b.at(i);
    if(b.at(i)==0){
      c++;
    }
  }
  if(c==1){
    cout<<a;	
    return 0;
  }
  else if(a<0){
    cout<<a-b.at(n-1);
  }
  else{
    cout<<a-b.at(0);
  }
}