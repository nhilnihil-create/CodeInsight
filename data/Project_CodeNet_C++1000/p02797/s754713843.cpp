#include <bits/stdc++.h>
using namespace std;
using ll=long long;
typedef pair<int,int>P;
 
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  for(int i=0;i<b;i++){
    cout<<c<<" ";
  }
 for(int j=0;j<a-b;j++){
     if(c>2){
     cout<<c-1<<" ";
     }
     else{
       cout<<c+1<<" ";
     }
 }
}
