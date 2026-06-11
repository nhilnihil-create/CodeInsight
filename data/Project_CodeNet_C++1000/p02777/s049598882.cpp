#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  string A,B;
  ll a,b;
  string C;
  cin>>A>>B>>a>>b>>C;
  if(A==C){
    cout<<a-1<<' '<<b<<endl;
  }
  else{
    cout<<a<<' '<<b-1<<endl;
  }
}