#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  for(int i=0;i<=k;i++){
    int d=b,e=c;
    for(int j=0;j<i;j++){
      d*=2;
    }
    for(int j=i;j<k;j++){
      e*=2;
    }
    if(a<d&&d<e){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
    
  