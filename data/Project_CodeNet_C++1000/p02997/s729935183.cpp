#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main(){
  int n,k;
  cin>>n>>k;
  if(k>(n-1)*(n-2)/2){
    cout<<-1<<endl;
  }
  else{
    int a=n*(n-1)/2-k;
    cout<<a<<endl;
    bool p=true;
    rep(i,1,n){
      rep(j,i+1,n+1){
        a--;
        cout<<i<<" "<<j<<endl;
        if(a==0){
          p=false;
          break;
        }
      }
      if(!p) break;
    }
  }
}