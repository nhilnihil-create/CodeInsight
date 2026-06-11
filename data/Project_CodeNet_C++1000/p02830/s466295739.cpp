#include<iostream>
using namespace std;
int main(){
  int N;
  string S,T;
cin>>N;
cin>>S>>T;
string h=S+T;
for(int i=0;i<N;i++){
    cout<<h[i]<<h[S.size()+i];
}
return 0;
}
