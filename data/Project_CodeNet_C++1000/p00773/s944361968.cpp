#include <iostream>
#include <cstdlib>
using namespace std;

int calc(int a,int b,int tax){
  return a*(100+tax)/100 + b*(100+tax)/100;
}

int main(){
  while(true){
    int x,y,s; cin>>x>>y>>s;
    if(x==0) break;
    int ans=0;

    for(int i=1;i<s;++i){
      for(int j=i;j<s;++j){

        if(s==calc(i,j,x))
          ans = max(ans, calc(i,j,y));
      }
    }
    cout << ans << endl;
  }
  return EXIT_SUCCESS;
}