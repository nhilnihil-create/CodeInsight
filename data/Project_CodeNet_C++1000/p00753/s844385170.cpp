#include <iostream>
#include <cstring>
using namespace std;

#define MAX (123456*2)

int main(){
  bool p[MAX+1];
  memset(p,true,sizeof(p));
  p[0] = p[1] = false;
  for(int i=0;i*i<=MAX;i++){
    if(p[i]){
      for(int j=i+i;j<=MAX;j+=i){
        p[j] = false;
      }
    }
  }

  int n;
  while(cin>>n,n){
    int ans = 0;
    for(int i=n+1;i<=2*n;i++){
      ans += p[i];
    }
    cout<<ans<<endl;
  }
}