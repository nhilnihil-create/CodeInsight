#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  while(1){
    int h,w;
    cin>>h>>w;
    if(h==0&&w==0)break;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if((i+j)%2)cout<<".";
        else cout<<"#";
      }
      cout<<endl;
    }
    cout<<endl;
  }
}

