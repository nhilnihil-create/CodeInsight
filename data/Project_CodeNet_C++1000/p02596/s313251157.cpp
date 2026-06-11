#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K;cin>>K;bool F=false;
  for(int X=1,Y=7%K;X<K+2;X++,Y=((Y*10)+7)%K){
    if(Y==0){
      cout<<X<<endl;F=true;break;
    }
  }
  if(!F)cout<<-1<<endl;
}