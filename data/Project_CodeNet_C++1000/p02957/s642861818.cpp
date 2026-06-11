#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAX=1e+9;
int main(){
  int A,B;
  cin>>A>>B;
  for(int i=0;i<=MAX;i++){
    if(abs(A-i)==abs(B-i)){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
}