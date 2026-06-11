#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  int tmp=C-(A-B);
  if(tmp<=0){
    cout<<0<<endl;
    return 0;
  }else{
    cout<<tmp<<endl;
  }
}