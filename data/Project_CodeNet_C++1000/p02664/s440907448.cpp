#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)
 
 
int main(){
  string t;
  cin>>t;
  rep(i,t.size()){
    if(t[i]=='?')t[i]='D';
  }
  cout<<t<<endl;
}