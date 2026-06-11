#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n==2){
    cout<<2<<endl;
    return 0;
  }
  while(1){
    int flag=1;
    
    for(int i=2;i*i<n;i++){
      if(n%i==0){
        flag=0;
        break;
      }
    }
    

      if(flag){
        cout<<n<<endl;
        return 0;
      }
    n++;
  }
  return 0;
}
