#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  int kotae=0;
  int keta1=0;
  int keta2=0;
  bool hantei=false;
  bool hantei2=false;
  bool hantei3=false;
  for(int i=0;i<10;i++){
    hantei=false;
    for(int l=0;l<n-2;l++){
      if(s[l]-'0'==i){
        keta1=l;
        hantei=true;
        break;
      }
    }
    if(hantei==true){
      for(int j=0;j<10;j++){
        hantei=false;
        for(int m=keta1+1;m<n-1;m++){
          if(s[m]-'0'==j){
            keta2=m;
            hantei=true;
            break;
          }
        }
        if(hantei==true){
          for(int k=0;k<10;k++){
            for(int o=keta2+1;o<n;o++){
              if(s[o]-'0'==k){
                //cout<<i<<j<<k<<"kore"<<s[keta1]<<s[keta2]<<s[o]<<" ";
                kotae++;
                break;
              }
            }
          }
        }
      }
    }
  }
  cout<<kotae<<endl;
  return 0;
}