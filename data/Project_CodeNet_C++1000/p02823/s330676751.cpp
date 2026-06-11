#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  if((b-a)%2==0){
    cout<<(b-a)/2<<endl;
  }else if(a-1<n-b){
    cout<<a+(b-a-1)/2<<endl;
  }else{
    cout<<(n-b+1)+(b-a-1)/2<<endl;
  }
}
