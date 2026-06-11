#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
 int a , as;
  int b , bs;
  cin>>a>>as>>b>>bs;
  int t;
  cin>>t;
  if(as <= bs){
   cout<<"NO"<<endl;
    return 0;
  }
  int net = as - bs;
  double val = (double)abs(b-a)/(double)net;
  if(val <= t){
   cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}