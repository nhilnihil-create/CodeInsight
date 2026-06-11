#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int n,k,c=0;
  cin>>n>>k;
  for(int i=1;i<=k;i++){
    int a=i/10,b=i%10;
    if(a>1&&b>1){
      for(int j=1;j<=n;j++){
        if(j==a*b)c++;
      }
    }
  }
  cout<<c;
}