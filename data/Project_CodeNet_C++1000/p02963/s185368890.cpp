#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  ll s;
  cin>>s;
  
  int a=sqrt(s);
  if(s!=1e18) a++;
  int b=a*a-s;
  int c;
  for(int i=1;i<=b;i++){
    if(b%i==0){
      c=i;
      break;
    }
  }
  cout<<0<<" "<<0<<" "<<a<<" "<<c<<" "<<b/c<<" "<<a<<endl;
  
}