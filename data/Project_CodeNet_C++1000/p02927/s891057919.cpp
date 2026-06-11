#include <bits/stdc++.h>
using namespace std;

int main(){
 long long a,b,c,d;
cin>>a>>b;
  c=0;
  for(int i=1;i<=a;i++){
    for(int j=10;j<=b;j++){
      if(i==(j/10)*(j%10)&&j/10>=2&&j%10>=2){
        c++;
      }
    }
  }
    cout<<c<<endl;
}

