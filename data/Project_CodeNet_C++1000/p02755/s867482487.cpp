#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  bool Q=true;
  for(int i=1;i<1001;i++){
    if(i*8/100==A&&i/10==B){
     Q=false;
     cout<<i<<endl;
     break;
    }
  }
  if(Q){
    cout<<-1<<endl;
  }
}
     