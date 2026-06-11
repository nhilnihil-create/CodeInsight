#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  bool b=0;
  int x[n];
  for(int i=0;i<n;i++) cin>>x[i];
  sort(x,x+n);
  for(int i=0;i<n;i++)
    if(x[i]==x[i+1]){
      b=1;
      break;
    }
      if(b==0)
    cout<<"YES"<<endl;
      else
    cout<<"NO"<<endl;
}
